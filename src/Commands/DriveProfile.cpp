#include "DriveProfile.h"
#include "Profiles.h"

#include <list>

DriveProfile::DriveProfile(std::list<Profile*>& seq)
{
	Requires(drive.get());

	std::string code = oi.get()->GetPrefs()->GetString("joy_btn_profile_abort");
	m_abortBtn = new frc::JoystickButton(oi.get()->GetStick(oi.get()->InterpretStick(code)), oi.get()->InterpretButton(code));

	m_motionControl = new MotionControl(drive.get(), seq);
}

DriveProfile::~DriveProfile()
{
	delete m_motionControl;
	delete m_abortBtn;
}

void DriveProfile::Initialize()
{
	m_motionControl->Initialize();
}

void DriveProfile::Execute()
{
	m_motionControl->Update();
}

bool DriveProfile::IsFinished()
{
	return m_abortBtn->Get() || m_motionControl->IsFinished();
}

void DriveProfile::End()
{
	m_motionControl->Finish();
}

void DriveProfile::Interrupted()
{

}
