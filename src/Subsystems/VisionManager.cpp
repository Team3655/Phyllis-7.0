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

	/*m_vision = new frc::VisionRunner<grip::GripPipeline>(
			m_cam,
			m_pipeline,
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
	// Get the USB camera from CameraServer
	cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture("cam0", 0);
	// Set the resolution
	camera.SetResolution(640, 480);
	// Get a CvSink. This will capture Mats from the Camera
	cs::CvSink cvSink = CameraServer::GetInstance()->GetVideo("cam0");
	// Setup a CvSource. This will send images back to the Dashboard
	cs::CvSource outputStream = CameraServer::GetInstance()->
			PutVideo("Proc", 640, 480);

	// Mats are very memory expensive. Lets reuse this Mat.
	cv::Mat mat;

	while (true) {
		// Tell the CvSink to grab a frame from the camera and put it
		// in the source mat.  If there is an error notify the output.
		if (cvSink.GrabFrame(mat) == 0) {
			// Send the output the error.
			outputStream.NotifyError(cvSink.GetError());
			// skip the rest of the current iteration
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
