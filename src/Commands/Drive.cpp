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

	std::string code = oi.get()->GetPrefs()->GetString("joy_btn_drive_mode");
	m_atSwitch = new frc::JoystickButton(oi.get()->GetStick(oi.get()->InterpretStick(code)), oi.get()->InterpretButton(code));
}

// Called just before this Command runs the first time
void Drive::Initialize()
{
	drive.get()->SetTalonMode(CANTalon::ControlMode::kPercentVbus);
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute()
{
	if (m_atSwitch->Get())
	{
		drive.get()->TankDrive(-oi.get()->GetYAxis(JOY_DRIVER_PORT), -oi.get()->GetYAxis(JOY_CODRIVER_PORT));
	}
	else
	{
		drive.get()->ArcadeDrive(-oi.get()->GetYAxis(JOY_CODRIVER_PORT), -oi.get()->GetXAxis(JOY_CODRIVER_PORT));
	}

	//drive.get()->SetPosition(frc::Preferences::GetInstance()->GetDouble("drive_test_pos", DRIVE_ENC_CPR));
	frc::SmartDashboard::PutNumber("Joy L", oi.get()->GetYAxis(0));
	frc::SmartDashboard::PutNumber("Joy R", oi.get()->GetXAxis(0));
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
