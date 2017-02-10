#ifndef VISION_MANAGER_H
#define VISION_MANAGER_H

#include <Commands/Subsystem.h>
#include <CameraServer.h>
#include <vision/VisionRunner.h>
#include <Preferences.h>

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

	// Processing
	frc::VisionRunner<grip::GripPipeline>* m_vision;

	int m_currentCam;

public:
	VisionManager();
	void InitDefaultCommand();

	void Initialize(frc::Preferences* prefs) override;
	void DashboardOutput(bool verbose = false) override;

	void SetCamera(int camera);
};

#endif // VISION_MANAGER_H
