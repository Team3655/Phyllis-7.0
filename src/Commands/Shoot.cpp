#include "Shoot.h"

Shoot::Shoot(double speedProp)
{
	Requires(shooter.get());
	Requires(fuelCollector.get());
	Requires(drive.get());
	m_isAligned = false;
	m_speedProportion = speedProp;

	m_abortBtn = new frc::JoystickButton(oi.get()->GetStick(JOY_BOARD_PORT), 2);

#ifdef TEMP
	m_shootBtn = new frc::JoystickButton(oi.get()->GetStick(JOY_DRIVER_PORT), 1);
#endif // TEMP

	m_timer = new frc::Timer();
}

void Shoot::Initialize()
{
	drive.get()->Disable();
	m_isAligned = false; // Get alignment
	m_timer->Start();
}

void Shoot::Execute()
{
#ifdef TEMP
	if (m_shootBtn->Get())
	{
		shooter.get()->Set(m_speedProportion * SHOOT_MAX_CPMS);
	}
	else
	{
		shooter.get()->Set(0);
	}
#else
	shooter.get()->Set(m_speedProportion * SHOOT_MAX_CPMS);
	if (m_timer->HasPeriodPassed(SHOOT_RESET_TIME / 1000))
	{
		fuelCollector.get()->IndexOne();
		m_timer->Reset();
	}
#endif // TEMP
}

bool Shoot::IsFinished()
{
	// When no more balls are present or not aligned
	return false || !m_isAligned || m_abortBtn->Get();
}

void Shoot::End()
{
	shooter.get()->Set(0);
	drive.get()->Enable();
}

void Shoot::Interrupted()
{

}
