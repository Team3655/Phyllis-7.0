#include "Shift.h"
#include "../CommandBase.h"

Shift::Shift() :
	CommandBase("Shift")
{
	Requires(drive.get());
}

// Called just before this Command runs the first time
void Shift::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Shift::Execute()
{
	drive.get()->Shift();
}

// Make this return true when this Command no longer needs to run execute()
bool Shift::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void Shift::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shift::Interrupted()
{

}
