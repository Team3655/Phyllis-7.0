#include "DelayForGear.h"
#include "../Logger.h"

DelayForGear::DelayForGear()
{
	Requires(gearCollector.get());
	Requires(drive.get());

	m_timer = new frc::Timer();
}

void DelayForGear::Initialize()
{
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "DelayForGear");
	m_timer->Start();
	drive.get()->Disable();
}

void DelayForGear::Execute()
{
	static bool triggered = false;
	bool gear = gearCollector.get()->IsGearPresent();
	if (gear && !triggered)
	{
		Logger::GetInstance()->Log("cmds", Logger::kInfo, "Gear present; timer reset");
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
	Logger::GetInstance()->Log("cmds", Logger::kExit, "DelayForGear");
	drive.get()->Enable();
}

void DelayForGear::Interrupted()
{
	Logger::GetInstance()->Log("cmds", Logger::kInfo, "DelayForGear interrupted");
}
