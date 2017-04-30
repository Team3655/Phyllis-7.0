///////////////////////////////////////////////////////////////////////////////
//
// Drive.cpp
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include "Drive.h"
#include "../Logger.h"

Drive::Drive() :
	CommandBase("Drive")
{
	Requires(drive.get());
}

void Drive::Initialize()
{
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "Drive");

	drive.get()->SetTalonMode(CANTalon::kThrottleMode);

	std::string code = oi.get()->GetPrefs()->GetString("joy_btn_drive_mode");
	m_atSwitch = new frc::JoystickButton(oi.get()->GetStick(2), 1);

	Logger::GetInstance()->Log("cmds", Logger::kInfo, "Drive mode switch button initialized to " + code);

	m_demoMarkiplayer =	1;
}

void Drive::Execute()
{
	if (oi->IsDemoMode())
	{
		m_demoMarkiplayer = MAGIC_PI / 10;
	}
	else
	{
		m_demoMarkiplayer = 1;
	}

	// TODO: add mode switch logs
	if (m_atSwitch->Get())
	{
		//drive.get()->TankDrive(oi.get()->GetYAxis(JOY_DRIVER_PORT) * DRIVE_MAX_SPEED, -oi.get()->GetYAxis(JOY_CODRIVER_PORT) * DRIVE_MAX_SPEED);
		drive.get()->TankDrive(oi.get()->GetYAxis(JOY_DRIVER_PORT) * m_demoMarkiplayer, -oi.get()->GetYAxis(JOY_CODRIVER_PORT ) * m_demoMarkiplayer);
	}
	else
	{
		//drive.get()->ArcadeDrive(-oi.get()->GetXAxis(JOY_CODRIVER_PORT) * DRIVE_MAX_SPEED, -oi.get()->GetYAxis(JOY_CODRIVER_PORT) * DRIVE_MAX_SPEED * .75);
		drive.get()->ArcadeDrive(-oi.get()->GetXAxis(JOY_CODRIVER_PORT) * m_demoMarkiplayer, -oi.get()->GetYAxis(JOY_CODRIVER_PORT) * .75 * m_demoMarkiplayer);
	}
}

bool Drive::IsFinished()
{
	return false;
}

void Drive::End()
{
	drive.get()->TankDrive(0, 0);
	Logger::GetInstance()->Log("cmds", Logger::kExit, "Drive");
}

void Drive::Interrupted()
{
	Logger::GetInstance()->Log("cmds", Logger::kInfo, "Drive interrupted");
	End();
}
