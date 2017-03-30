#include "DriveProfile.h"
#include "Profiles.h"

#include "../Logger.h"

#include <list>

DriveProfile::DriveProfile(std::list<Profile*>& seq)
{
	Requires(drive.get());

	m_seq = seq;
}

DriveProfile::~DriveProfile()
{
	delete m_motionControl;
	delete m_abortBtn;
}

void DriveProfile::Initialize()
{
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "DriveProfile");

	std::string code = oi.get()->GetPrefs()->GetString("joy_btn_profile_abort");
	m_abortBtn = new frc::JoystickButton(oi.get()->GetStick(oi.get()->InterpretStick(code)), oi.get()->InterpretButton(code));

	Logger::GetInstance()->Log("cmds", Logger::kInfo, "DriveProfile Abort Button initialized to " + code);

	m_motionControl = new MotionControl(drive, m_seq);
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
	Logger::GetInstance()->Log("cmds", Logger::kExit, "DriveProfile");
}

void DriveProfile::Interrupted()
{
	Logger::GetInstance()->Log("cmds", Logger::kInfo, "DriveProfile interrupted");
}
