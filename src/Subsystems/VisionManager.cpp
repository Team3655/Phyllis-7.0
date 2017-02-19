#include "VisionManager.h"
#include "../Commands/ManageVision.h"

VisionManager::VisionManager() :
	frc::Subsystem("Vision Manager")
{
}

VisionManager::~VisionManager()
{
	delete m_vision;
	delete m_visionThread;
}

void VisionManager::InitDefaultCommand()
{
	SetDefaultCommand(new ManageVision());
}

void VisionManager::Initialize(frc::Preferences* prefs)
{
	m_cs = frc::CameraServer::GetInstance();

	m_currentCamID = CS_CAM_PEG_PORT;
	m_currentCam = m_cs->StartAutomaticCapture(CS_CAM_PEG_PORT);
	m_currentCam.SetResolution(480, 360);
	m_currentCam.SetFPS(m_currentFPS);

	m_vision = new frc::VisionRunner<grip::GripPipeline>(
			m_currentCam,
			new grip::GripPipeline(),
			[&](grip::GripPipeline& pipeline)
			{
				frc::SmartDashboard::PutNumber("CenterX", pipeline.getTargetCenterX(0));
				frc::SmartDashboard::PutNumber("Processing Time", pipeline.getProcTime());
			});
	m_lock = new std::mutex();

	m_currentFPS = prefs->GetDouble("cam_fps");
}

void VisionManager::DashboardOutput(bool verbose)
{
	m_lock->lock();
	frc::SmartDashboard::PutBoolean("Vision Processing Running", m_isRunning);
	m_lock->unlock();

	if (verbose)
	{

	}
}

void VisionManager::vision_thread()
{
	while (true)
	{
		m_vision->RunOnce();

		m_lock->lock();
		if (!m_isRunning)
		{
			m_lock->unlock();
			break;
		}
		m_lock->unlock();
		sleep(20);
	}
}

void VisionManager::StartProc()
{
	m_isRunning = true;
	m_visionThread = new std::thread(&VisionManager::vision_thread, this);
	m_visionThread->detach();
}

void VisionManager::SwitchCamera(int id)
{
	m_lock->lock();
	m_isRunning = false;
	m_lock->unlock();

	m_currentCamID = id == 1 ? CS_CAM_SHOOT_PORT : CS_CAM_PEG_PORT;

	m_currentCam = m_cs->StartAutomaticCapture(m_currentCamID);
	m_currentCam.SetResolution(CS_CAM_RES_X, CS_CAM_RES_Y);
	m_currentCam.SetFPS(m_currentFPS);

	grip::GripPipeline* g = new grip::GripPipeline();
	g->setStuff((m_currentCamID == 0) ? PEG : BOILER);

	m_vision = new frc::VisionRunner<grip::GripPipeline>(
			m_currentCam,
			g,
			[&](grip::GripPipeline& pipeline)
			{
				frc::SmartDashboard::PutNumber("CenterX", pipeline.getTargetCenterX(0));
				frc::SmartDashboard::PutNumber("Processing Time", pipeline.getProcTime());
			});

	m_lock->lock();
	m_isRunning = true;
	m_lock->unlock();

	StartProc();
}
