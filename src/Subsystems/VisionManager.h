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
#include "Logger.h"

// Summary:
// 	Class for managing cameras and vision processing
class VisionManager : public frc::Subsystem, public ExtSubsystem
{
private:
	frc::CameraServer* m_cs;
	cs::UsbCamera m_cam;
	static cs::CvSink m_sink;
	static cs::CvSource m_output;

	static grip::GripPipeline* m_pipeline;

	static bool m_isRunning;
	static std::thread* m_visionThread;
	static std::mutex* m_lock;

	// Processing
	frc::VisionRunner<grip::GripPipeline>* m_vision;

	static Logger* m_log;

	static void vision_thread();

public:
	VisionManager();
	~VisionManager();
	void InitDefaultCommand();

	void Initialize(frc::Preferences* prefs) override;
	void DashboardOutput(bool verbose = false) override;

	void StartProc();

	bool IsRunning() { return m_isRunning; }
};

#endif // VISION_MANAGER_H
