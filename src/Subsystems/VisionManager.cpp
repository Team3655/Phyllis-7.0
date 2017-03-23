#include "VisionManager.h"

cs::CvSink VisionManager::m_sink;
cs::CvSource VisionManager::m_output;
grip::GripPipeline* VisionManager::m_pipeline;
bool VisionManager::m_isRunning = false;
std::thread* VisionManager::m_visionThread;
std::mutex* VisionManager::m_lock;


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
	cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture("cam0", 0);
	camera.SetResolution(640, 480);
	cs::CvSink cvSink = CameraServer::GetInstance()->GetVideo("cam0");
	cs::CvSource outputStream = CameraServer::GetInstance()->PutVideo("Proc", 640, 480);

	cv::Mat mat;

	while (true) {
		if (cvSink.GrabFrame(mat) == 0)
		{
			outputStream.NotifyError(cvSink.GetError());
			continue;
		}
		// Put a rectangle on the image
		//rectangle(mat, cv::Point(100, 100), cv::Point(400, 400),
		//		cv::Scalar(255, 255, 255), 5);
		/*cv::cvtColor(mat, mat, cv::COLOR_BGR2GRAY);

		cv::inRange(mat,
				cv::Scalar(0, 200, 200),
				cv::Scalar(100, 255, 255),
				mat);*/
		m_pipeline->Process(mat);

		frc::SmartDashboard::PutNumber("CenterX", m_pipeline->getTargetCenterX(0));
		frc::SmartDashboard::PutNumber("Processing Time", m_pipeline->getProcTime());
		frc::SmartDashboard::PutNumber("Targets", m_pipeline->getTargets());

		// Give the output stream a new image to display
		outputStream.PutFrame(mat);
	}

	/*cv::Mat frame;
	cs::CvSink cvSink = CameraServer::GetInstance()->GetVideo();
	while (true)
	{
		if (cvSink.GrabFrame(frame) == 0)
		{
			std::cout << cvSink.GetError() << std::endl;
		}
		std::cout << "pre proc" << std::endl;
		m_pipeline->Process(frame);
		std::cout << "post proc" << std::endl;

		m_output.PutFrame(m_pipeline->hslThresholdOutput); //ERROR here with !fixedSize()

		m_lock->lock();
		if (!m_isRunning)
		{
			m_lock->unlock();
			break;
		}
		m_lock->unlock();
		sleep(500);*/

}

void VisionManager::StartProc()
{
	m_isRunning = true;
	m_visionThread = new std::thread(&VisionManager::vision_thread);
	m_visionThread->detach();
}
