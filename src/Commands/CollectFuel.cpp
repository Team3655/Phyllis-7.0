#include "CollectFuel.h"

CollectFuel::CollectFuel()
{
	Requires(fuelCollector.get());

	m_collectBtn = new frc::JoystickButton(oi.get()->GetStick(0), 3);
}

// Called just before this Command runs the first time
void CollectFuel::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CollectFuel::Execute()
{
	static bool intake = false;
	if (m_collectBtn->Get())
	{
		fuelCollector.get()->SetIntake(intake);
		intake = !intake;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool CollectFuel::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CollectFuel::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CollectFuel::Interrupted()
{

}
