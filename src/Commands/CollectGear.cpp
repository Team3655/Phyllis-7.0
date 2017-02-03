#include "CollectGear.h"

CollectGear::CollectGear()
{
	Requires(gearCollector.get());

	m_intakeBtn = new frc::JoystickButton(oi.get()->GetStick(0), 1);
}

// Called just before this Command runs the first time
void CollectGear::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CollectGear::Execute()
{
	if (m_intakeBtn->Get())
	{
		gearCollector.get()->SetIntake();
	}
	else
	{
		gearCollector.get()->Stop();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool CollectGear::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CollectGear::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CollectGear::Interrupted()
{

}
