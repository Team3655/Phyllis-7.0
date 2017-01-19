#include "Shoot.h"

Shoot::Shoot()
{
	Requires(shooter.get());
	Requires(fuelCollector.get());
	m_isAligned = false;
}

// Called just before this Command runs the first time
void Shoot::Initialize()
{
	m_isAligned = false; // Get alignment
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute()
{
	double y = oi.get()->GetAxisY();
	shooter.get()->Set(y);
	if (shooter.get()->IsAtSpeed())
	{
		fuelCollector.get()->SetOpen(true);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished()
{
	// When no more balls are present or not aligned
	return false || m_isAligned;
}

// Called once after isFinished returns true
void Shoot::End()
{
	fuelCollector.get()->SetOpen(false);
	shooter.get()->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted()
{

}
