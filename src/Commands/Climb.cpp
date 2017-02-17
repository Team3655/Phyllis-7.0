#include "Climb.h"

Climb::Climb()
{
	Requires(climber.get());

	std::string code = oi.get()->GetPrefs()->GetString("joy_btn_climb_stop");
	m_stopBtn = new frc::JoystickButton(oi.get()->InterpretStick(code), oi.get()->InterpretButton(code));
	m_stopBtn->CancelWhenPressed(this); // Try or use IsFinished
}

Climb::~Climb()
{
	delete m_stopBtn;
}

void Climb::Initialize()
{
}

void Climb::Execute()
{
	climber.get()->SetSpeed(CLIMB_SPEED);
}

bool Climb::IsFinished()
{
	return false; //m_stopBtn->Get();
}

void Climb::End()
{
	climber.get()->SetSpeed(0);
}

void Climb::Interrupted()
{
}
