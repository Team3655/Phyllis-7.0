///////////////////////////////////////////////////////////////////////////////
//
// Drive.cpp
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include "Drive.h"

Drive::Drive() :
	CommandBase("")
{
	Requires(drive.get());
}

// Called just before this Command runs the first time
void Drive::Initialize()
{
	drive.get()->SetTalonMode(CANTalon::TalonControlMode::kPositionMode);
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute()
{
	//drive.get()->TankDrive(-oi.get()->GetYAxis(JOY_DRIVER_PORT), -oi.get()->GetYAxis(JOY_CODRIVER_PORT));
	drive.get()->SetPosition(DRIVE_ENC_CPR * 5);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Drive::End()
{
	drive.get()->TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted()
{

}
