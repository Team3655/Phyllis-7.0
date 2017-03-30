#include "VisionManager.h"

cs::CvSink VisionManager::m_sink;
cs::CvSource VisionManager::m_output;
grip::GripPipeline* VisionManager::m_pipeline;
bool VisionManager::m_isRunning = false;
std::thread* VisionManager::m_visionThread;
std::mutex* VisionManager::m_lock;
Logger* VisionManager::m_log;

VisionManager::VisionManager() :
	frc::Subsystem("Vision")
{
}

VisionManager::~VisionManager()
{
	m_log->Log("vision", Logger::kExit);
	delete m_vision;
	delete m_visionThread;
}

void VisionManager::InitDefaultCommand()
{
}

void VisionManager::Initialize(frc::Preferences* prefs)
{
	m_log = Logger::GetInstance();
	m_log->AddLog(this, "vision");
	m_log->Log(this, Logger::kEnter);

	m_cs = frc::CameraServer::GetInstance();

	m_pipeline = new grip::GripPipeline();
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
	// Get the USB camera from CameraServer
	cs::UsbCamera camera = frc::CameraServer::GetInstance()->StartAutomaticCapture("cam0", 0);
	camera.SetFPS(10);
	camera.SetResolution(640, 480);

	m_log->Log("vision", Logger::kInfo, "Camera initialized to " + camera.GetPath());
	cs::VideoMode vm = camera.GetVideoMode();
	m_log->Log("vision", Logger::kInfo, "FPS: " + std::to_string(vm.fps) + " Res x: " + std::to_string(vm.width) + " y: " + std::to_string(vm.height));

	cs::CvSink cvSink = frc::CameraServer::GetInstance()->GetVideo("cam0");
	cs::CvSource outputStream = frc::CameraServer::GetInstance()->PutVideo("Proc", 640, 480);

	m_log->Log("vision", Logger::kInfo, "Source initialized as " + outputStream.GetName());

	cv::Mat mat;

	while (true)
	{
		if (cvSink.GrabFrame(mat) == 0)
		{
			outputStream.NotifyError(cvSink.GetError());
			m_log->Log("vision", Logger::kError, cvSink.GetError());
			continue;
		}

		m_pipeline->Process(mat);

		frc::SmartDashboard::PutNumber("CenterX", m_pipeline->getTargetCenterX(0));
		frc::SmartDashboard::PutNumber("Processing Time", m_pipeline->getProcTime());
		frc::SmartDashboard::PutNumber("Targets", m_pipeline->getTargets());

		// Give the output stream a new image to display
		outputStream.PutFrame(mat);
	}
}

void VisionManager::StartProc()
{
	m_isRunning = true;
	m_log->Log("vision", Logger::kInfo, "Vision processing started");
	m_visionThread = new std::thread(&VisionManager::vision_thread);
	m_visionThread->detach();
}
