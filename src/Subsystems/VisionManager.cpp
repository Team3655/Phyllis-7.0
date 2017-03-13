#include "VisionManager.h"

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
}

void VisionManager::Initialize(frc::Preferences* prefs)
{
	m_cs = frc::CameraServer::GetInstance();

	m_cam = m_cs->StartAutomaticCapture();
	m_cam.SetResolution(CS_CAM_RES_X, CS_CAM_RES_Y);
	m_cam.SetFPS(CS_CAM_FPS_DEFAULT);

	m_sink = m_cs->GetVideo(m_cam);
	m_output = m_cs->PutVideo("Proc", CS_CAM_RES_X, CS_CAM_RES_Y);

	m_pipeline = new grip::GripPipeline();

	/*m_vision = new frc::VisionRunner<grip::GripPipeline>(
			m_cam,
			,
			[&](grip::GripPipeline& pipeline)
			{
				frc::SmartDashboard::PutNumber("CenterX", pipeline.getTargetCenterX(0));
				frc::SmartDashboard::PutNumber("Processing Time", pipeline.getProcTime());
				frc::SmartDashboard::PutNumber("Targets", pipeline.getTargets());
				m_output.PutFrame(pipeline.getProcessedFrame());
			});*/
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
		//m_vision->RunOnce();
		cv::Mat frame;
		int i = 0;
		if ((i = m_sink.GrabFrame(frame)) == 0)
		{
			std::cout << "HILFE" << std::endl;
		}
		m_pipeline->Process(frame);
		std::cout << i << std::endl;

		//m_output.PutFrame(m_pipeline->hslThresholdOutput); ERROR here with !fixedSize()

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
