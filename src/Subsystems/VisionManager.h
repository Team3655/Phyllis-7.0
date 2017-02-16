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
#include "../RobotMap.h"

// Summary:
// 	Class for managing cameras and vision processing
class VisionManager : public frc::Subsystem, public ExtSubsystem
{
private:
	frc::CameraServer* m_cs;
	cs::UsbCamera m_currentCam;

	cs::CvSink m_sink;
	cv::Mat m_mat;

	bool m_isRunning = false;
	std::thread* m_visionThread;
	std::mutex* m_lock;

	int m_currentCamID = -1;
	int m_currentFPS = CS_CAM_FPS_DEFAULT;

	// Processing
	frc::VisionRunner<grip::GripPipeline>* m_vision;

	void vision_thread();

public:
	VisionManager();
	~VisionManager();
	void InitDefaultCommand();

	void Initialize(frc::Preferences* prefs) override;
	void DashboardOutput(bool verbose = false) override;

	void StartProc();

	void SwitchCamera(int id);

	bool IsRunning() { return m_isRunning; }
};

#endif // VISION_MANAGER_H
