#ifndef VISION_MANAGER_H
#define VISION_MANAGER_H

#include <Commands/Subsystem.h>
#include <CameraServer.h>

#include "../ExtSubsystem.h"

// Summary:
// 	Class for managing cameras and vision processing
class VisionManager : public frc::Subsystem, public ExtSubsystem
{
private:
	frc::CameraServer* m_cs;
	cs::UsbCamera m_pegCam;
	cs::UsbCamera m_shootCam;

	int m_currentCam;

public:
	VisionManager();
	void InitDefaultCommand();

	void Initialize() override;
	void DashboardOutput(bool verbose = false) override;

	void SetCamera(int camera);
};

#endif  // VISION_MANAGER_H
