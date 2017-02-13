#include "ManageVision.h"

ManageVision::ManageVision()
{
	Requires(visionManager.get());
}

void ManageVision::Initialize()
{
	visionManager.get()->StartProc();

	std::string code = oi.get()->GetPrefs()->GetString("joy_btn_cam_switch");
	m_switchCam = new JoystickButton(oi.get()->GetStick(oi.get()->InterpretStick(code)), oi.get()->InterpretButton(code));
}

void ManageVision::Execute()
{
	if (m_switchCam->Get()) m_toggle = !m_toggle;


}

bool ManageVision::IsFinished()
{
	return false;
}

void ManageVision::End()
{

}

void ManageVision::Interrupted()
{

}
