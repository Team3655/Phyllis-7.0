#include "Shoot.h"

Shoot::Shoot(double speedProp)
{
	Requires(shooter.get());
	Requires(fuelCollector.get());
	Requires(drive.get());

	m_isAligned = false;
	m_speedProportion = speedProp;
}

void Shoot::Initialize()
{
	std::string code = oi.get()->GetPrefs()->GetString("joy_btn_shoot_end");
	m_abortBtn = new frc::JoystickButton(oi.get()->GetStick(oi.get()->InterpretStick(code)), oi.get()->InterpretButton(code));

	m_index = new frc::JoystickButton(oi.get()->GetStick(2), 2);

	m_timer = new frc::Timer();

	drive.get()->Disable();
	m_isAligned = false; // Get alignment
	m_timer->Start();
}

void Shoot::Execute()
{
	shooter.get()->Set(m_speedProportion * SHOOT_MAX_SPEED);
	if (m_timer->HasPeriodPassed(SHOOT_RESET_TIME / 1000))
	{
		fuelCollector.get()->IndexOne();
		m_timer->Reset();
	}
}

bool Shoot::IsFinished()
{
	// When no more balls are present or not aligned or abort pressed
	return m_abortBtn->Get(); //!isAligned
}

void Shoot::End()
{
	shooter.get()->Set(0);
	drive.get()->Enable();
}

void Shoot::Interrupted()
{

}
