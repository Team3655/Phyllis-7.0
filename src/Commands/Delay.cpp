#include "Delay.h"

Delay::Delay(double delay)
{
	Requires(drive.get());

	m_delay = delay;
	m_delayTimer = new frc::Timer();
}

void Delay::Initialize()
{
	drive.get()->Disable();
	m_delayTimer->Start();
}

void Delay::Execute()
{
	// Lights Maybe
}

bool Delay::IsFinished()
{
	return m_delayTimer->HasPeriodPassed(m_delay);
}

void Delay::End()
{
	drive.get()->Enable();
}

void Delay::Interrupted()
{
}
