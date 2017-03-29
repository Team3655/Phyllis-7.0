#include "DelayForGear.h"

DelayForGear::DelayForGear()
{
	Requires(gearCollector.get());
	Requires(drive.get());

	m_timer = new frc::Timer();
}

void DelayForGear::Initialize()
{
	m_timer->Start();
	drive.get()->Disable();
}

void DelayForGear::Execute()
{
	static bool triggered = false;
	bool gear = gearCollector.get()->IsGearPresent();
	if (gear && !triggered)
	{
		m_timer->Reset();
		triggered = true;
	}
	else if (gear)
	{
		if (m_timer->HasPeriodPassed(3))
		{
			m_end = true;
		}
	}
	if (!gear)
	{
		triggered = false;
	}
}

bool DelayForGear::IsFinished()
{
	return m_end;
}

void DelayForGear::End()
{
	drive.get()->Enable();
}

void DelayForGear::Interrupted()
{

}
