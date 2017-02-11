#ifndef VISION_MANAGER_H
#define VISION_MANAGER_H

#include <Commands/Subsystem.h>
#include <CameraServer.h>
#include <vision/VisionRunner.h>
#include <Wpilib.h>
#include <Preferences.h>
#include <thread>
#include <mutex>

#include "../GripPipeline.h"
#include "../ExtSubsystem.h"

// Summary:
// 	Class for managing cameras and vision processing
class VisionManager : public frc::Subsystem, public ExtSubsystem
{
private:
	frc::CameraServer* m_cs;
	cs::UsbCamera m_pegCam;
	cs::UsbCamera m_shootCam;

	cs::CvSink m_sink;
	cv::Mat m_mat;

	// thread
	std::thread* m_visionThread;
	std::mutex m_resourceLock; // unused so far
	bool m_isRunning = false;

	// Processing
	frc::VisionRunner<grip::GripPipeline>* m_vision;

	int m_currentCam;

	void vision_thread();

public:
	VisionManager();
	void InitDefaultCommand();

	void Initialize(frc::Preferences* prefs) override;
	void DashboardOutput(bool verbose = false) override;

	void SetCamera(int camera);

	void StartProc();

	bool IsRunning() { return m_isRunning; }
};

#endif // VISION_MANAGER_H
