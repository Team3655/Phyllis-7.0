#include "CollectGear.h"

CollectGear::CollectGear(bool direction)
{
	Requires(gearCollector.get());

	m_direction = direction;

#ifdef TEMP
	m_intakeBtn = new frc::JoystickButton(oi.get()->GetStick(0), 3);
#endif

	m_endBtn = new frc::JoystickButton(oi.get()->GetStick(JOY_BOARD_PORT), 3);
}

void CollectGear::Initialize()
{
}

void CollectGear::Execute()
{
#ifdef TEMP
	if (m_intakeBtn->Get())
	{
		gearCollector.get()->SetIntake(m_direction ? FORWARD : BACKWARD);
	}
	else
	{
		gearCollector.get()->Stop();
	}
#else
	gearCollector.get()->SetIntake(m_direction ? FORWARD : BACKWARD);
#endif
}

bool CollectGear::IsFinished()
{
	return m_endBtn->Get();
}

void CollectGear::End()
{
	gearCollector.get()->Stop();
}

void CollectGear::Interrupted()
{
}
