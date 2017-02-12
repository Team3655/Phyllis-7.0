#include "VisionManager.h"
#include "../RobotMap.h"

VisionManager::VisionManager() :
	frc::Subsystem("Vision Manager")
{
	m_currentCam = -1;
}

void VisionManager::InitDefaultCommand()
{
	// SetDefaultCommand(new MySpecialCommand());
}

void VisionManager::Initialize(frc::Preferences* prefs)
{
	m_cs = frc::CameraServer::GetInstance();

	m_vision = new frc::VisionRunner<grip::GripPipeline>(
			cs::UsbCamera(),
			new grip::GripPipeline(),
			[](grip::GripPipeline& pipeline)
			{
				frc::SmartDashboard::PutNumber("CenterX", pipeline.getTargetCenterX(0));
				frc::SmartDashboard::PutNumber("Processing Time", pipeline.getProcTime());
			});

	m_currentCam = 0;
	m_pegCam = m_cs->StartAutomaticCapture(0);
	m_sink = m_cs->GetVideo();
}

void VisionManager::DashboardOutput(bool verbose)
{
	if (verbose)
	{

	}
}

void VisionManager::SetCamera(int camera)
{
	switch (camera)
	{
	default:
	case 0:
		m_pegCam = m_cs->StartAutomaticCapture(camera);
		break;
	case 1:
		m_shootCam = m_cs->StartAutomaticCapture(camera);
		break;
	}
	m_currentCam = camera;
}

void VisionManager::StartProc()
{
	m_vision->RunForever();
	m_isRunning = true;
}
