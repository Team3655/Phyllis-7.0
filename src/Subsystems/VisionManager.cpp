#include "VisionManager.h"
#include "../RobotMap.h"
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

	m_currentCam = CS_CAM_PEG_PORT;
	m_currentCam = m_cs->StartAutomaticCapture(CS_CAM_PEG_PORT);
	m_currentCam.SetResolution(480, 360);

	m_vision = new frc::VisionRunner<grip::GripPipeline>(
			m_currentCam,
			new grip::GripPipeline(),
			[&](grip::GripPipeline& pipeline)
			{
				frc::SmartDashboard::PutNumber("CenterX", pipeline.getTargetCenterX(0));
				frc::SmartDashboard::PutNumber("Processing Time", pipeline.getProcTime());
			});
	m_lock = new std::mutex();
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
		if (m_isRunning)
		{
			m_lock->unlock();
			break;
		}
		m_lock->unlock();
	}
}

void VisionManager::StartProc()
{
	m_visionThread = new std::thread(&VisionManager::vision_thread, this);
	m_visionThread->detach();
	m_isRunning = true;
}

void VisionManager::SwitchCamera()
{
	m_lock->lock();
	m_isRunning = false;
	m_lock->unlock();

	m_currentCam = m_cs->StartAutomaticCapture(CS_CAM_PEG_PORT);
	m_currentCam.SetResolution(CS_CAM_RES_X, CS_CAM_RES_Y);

	m_vision = new frc::VisionRunner<grip::GripPipeline>(
			m_currentCam,
			new grip::GripPipeline(),
			[&](grip::GripPipeline& pipeline)
			{
				frc::SmartDashboard::PutNumber("CenterX", pipeline.getTargetCenterX(0));
				frc::SmartDashboard::PutNumber("Processing Time", pipeline.getProcTime());
			});

	m_visionThread = new std::thread(&VisionManager::vision_thread, this);

}
