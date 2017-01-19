#include "CameraServerWrapper.h"
#include "../RobotMap.h"

CameraServerWrapper::CameraServerWrapper() :
	Subsystem("Camera Server Wrapper")
{
	//m_camera = CameraServer::GetInstance();
	//m_visionProc = new grip::GripPipeline();
}

void CameraServerWrapper::InitDefaultCommand()
{
	//SetDefaultCommand(new MySpecialCommand());
}

void CameraServerWrapper::StartStream()
{
	//m_usbCamera = m_camera->StartAutomaticCapture();
	//m_usbCamera->SetFPS(20);
	//m_usbCamera->SetResolution(360, 240);
}

void CameraServerWrapper::StartProc()
{
	m_isProc = true;
	//m_cvSink = &CameraServer::GetInstance()->GetVideo();

}

void CameraServerWrapper::EndProc()
{
	m_isProc = false;
}

void CameraServerWrapper::Proccess()
{
	if (!m_isProc) return;

	//m_cvSink->GrabFrame(*m_currentFrame);
	//m_visionProc->process(*m_currentFrame);
}
