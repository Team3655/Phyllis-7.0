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
	m_drive = drive.get();
	m_oi = oi.get();
}

// Called just before this Command runs the first time
void Drive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute()
{
	m_drive->TankDrive(m_oi->GetAxisX(), m_oi->GetAxisY());
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Drive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted()
{

}
