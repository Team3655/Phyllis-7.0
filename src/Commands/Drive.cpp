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
	CommandBase("Drive")
{
	Requires(drive.get());
}

void Drive::Initialize()
{
	drive.get()->SetTalonMode(CANTalon::ControlMode::kPercentVbus);

	std::string code = oi.get()->GetPrefs()->GetString("joy_btn_drive_mode");
	m_atSwitch = new frc::JoystickButton(oi.get()->GetStick(oi.get()->InterpretStick(code)), oi.get()->InterpretButton(code));
}

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
}

bool Drive::IsFinished()
{
	return false;
}

void Drive::End()
{
	drive.get()->TankDrive(0, 0);
}

void Drive::Interrupted()
{

}
