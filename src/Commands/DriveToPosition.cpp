#include "DriveToPosition.h"

DriveToPosition::DriveToPosition()
{
	Requires(drive.get());
}

// Called just before this Command runs the first time
void DriveToPosition::Initialize()
{
	//drive.get()->SetTalonMode(CANTalon::TalonControlMode::kPositionMode);
}

// Called repeatedly when this Command is scheduled to run
void DriveToPosition::Execute()
{
	drive.get()->SetPosition(5000);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveToPosition::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveToPosition::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveToPosition::Interrupted()
{

}
