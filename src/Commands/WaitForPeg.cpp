#include "WaitForPeg.h"

WaitForPeg::WaitForPeg(frc::JoystickButton* abortBtn)
{
	Requires(drive.get());
	Requires(gearCollector.get());

	//frc::Preferences* prefs = oi.get()->GetPrefs();
	//std::string code;

	m_abortBtn = abortBtn;

	//code = prefs->GetString("joy_btn_peg_abort");
	//m_abortBtn = new frc::JoystickButton(oi.get()->InterpretStick(code), oi.get()->InterpretButton(code));
}

WaitForPeg::~WaitForPeg()
{
	delete m_abortBtn;
}

void WaitForPeg::Initialize()
{
	drive.get()->Disable();
}

void WaitForPeg::Execute()
{
	// Maybe flash lights
}

bool WaitForPeg::IsFinished()
{
	return !gearCollector.get()->IsGearPresent() || m_abortBtn->Get();
}

void WaitForPeg::End()
{
	drive.get()->Enable();
}

void WaitForPeg::Interrupted()
{
}
