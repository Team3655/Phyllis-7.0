///////////////////////////////////////////////////////////////////////////////
//
// OI.cpp
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include "OI.h"
#include "RobotMap.h"

#include "Commands/Shoot.h"
#include "Commands/Shift.h"
#include "Commands/CollectGear.h"
#include "Commands/CollectFuel.h"

#include <string>
#include <sstream>

OI::OI() :
	m_driver(new Joystick(JOY_DRIVER_PORT)),
	m_coDriver(new Joystick(JOY_CODRIVER_PORT)),
	m_board(new Joystick(JOY_BOARD_PORT)),
	m_prefs(frc::Preferences::GetInstance())
{
	int code = m_prefs->GetInt("joy_btn_gear_collect", 2);
	m_collectGear = new JoystickButton(GetStick(InterpretStick(code)), InterpretButton(code));
	m_collectGear->WhenPressed(new CollectGear(true));

	code = m_prefs->GetInt("joy_btn_gear_eject", 3);
	m_ejectGear = new JoystickButton(GetStick(InterpretStick(code)), InterpretButton(code));
	m_ejectGear->WhenPressed(new CollectGear(false));

	code = m_prefs->GetInt("joy_btn_fuel_intake", 23);
	m_collectFuel = new JoystickButton(GetStick(InterpretStick(code)), InterpretButton(code));
	m_collectFuel->WhenPressed(new CollectFuel());

	//code = m_prefs->GetInt("joy_btn_shoot", 1);
	//m_shoot = new JoystickButton(GetStick(InterpretStick(code)), InterpretButton(code));
	//m_shoot->WhenPressed(new Shoot());

	code = m_prefs->GetInt("joy_btn_drive_shift", 5);
	m_shift = new JoystickButton(GetStick(InterpretStick(code)), InterpretButton(code));
	m_shift->WhenPressed(new Shift());
}

OI::~OI()
{
	delete m_driver;
	delete m_coDriver;
	delete m_board;
	delete m_shoot;
	delete m_shift;
	delete m_collectGear;
	delete m_ejectGear;
	delete m_collectFuel;
}

int OI::InterpretStick(std::string& code)
{
	// Lazy as shit so I'm not doing this efficiently
	return std::stoi(std::string(code[0]));
}

int OI::InterpretButton(std::string& code)
{
	// Here too
	std::string str;
	bool b = false;
	for (int i = 0; i < code.length(); i++)
	{
		if (code[i] == '-') b = true;
		if (b)
			str += code[i];
	}
	return std::stoi(str);
}

double OI::Deadband(double input)
{
	return input <= m_deadband && input >= -m_deadband ? 0 : input;
}

Joystick* OI::GetStick(int stick)
{
	switch (stick)
	{
	default:
	case 0:
		return m_driver;
		break;
	case 1:
		return m_coDriver;
		break;
	case 2:
		return m_board;
		break;
	}
}

double OI::GetXAxis(int stick)
{
	return GetStick(stick)->GetAxis(Joystick::AxisType::kXAxis);
}

double OI::GetYAxis(int stick)
{
	return GetStick(stick)->GetAxis(Joystick::AxisType::kYAxis);
}

double OI::GetZAxis(int stick)
{
	return GetStick(stick)->GetAxis(Joystick::AxisType::kZAxis);
}

void OI::SetDeadband(double band)
{
	EnableDeadband(true);
	m_deadband = band;
}
