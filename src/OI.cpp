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

OI::OI() :
	m_driver(new Joystick(JOY_DRIVER_PORT)),
	m_codriver(new Joystick(JOY_CODRIVER_PORT)),
	m_board(new Joystick(JOY_BOARD_PORT)),
	m_board2(new Joystick(JOY_BOARD_PORT2)),
	m_prefs(frc::Preferences::GetInstance())
{

}

OI::~OI()
{
	delete m_driver;
	delete m_codriver;
	delete m_board;
	delete m_shoot;
	delete m_shift;
	delete m_collectGear;
	delete m_ejectGear;
	delete m_collectFuel;
}

void OI::Initialize()
{
	std::string code = m_prefs->GetString("joy_btn_gear_collect");
	m_collectGear = new JoystickButton(GetStick(InterpretStick(code)), InterpretButton(code));
	m_collectGear->WhenPressed(new CollectGear(true));

	code = m_prefs->GetString("joy_btn_gear_eject");
	m_ejectGear = new JoystickButton(GetStick(InterpretStick(code)), InterpretButton(code));
	m_ejectGear->WhenPressed(new CollectGear(false));

	code = m_prefs->GetString("joy_btn_fuel_intake");
	m_collectFuel = new JoystickButton(GetStick(InterpretStick(code)), InterpretButton(code));
	m_collectFuel->WhenPressed(new CollectFuel());

	code = m_prefs->GetString("joy_btn_shoot");
	m_shoot = new JoystickButton(GetStick(InterpretStick(code)), InterpretButton(code));
	m_shoot->WhenPressed(new Shoot(m_prefs->GetDouble("shoot_speed")));

	code = m_prefs->GetString("joy_btn_drive_shift");
	m_shift = new JoystickButton(GetStick(InterpretStick(code)), InterpretButton(code));
	m_shift->WhenPressed(new Shift());
}

int OI::InterpretStick(std::string& code)
{
	if (code.length() <= 0) return 0;
	return code[0] - 48;
}

int OI::InterpretButton(std::string& code)
{
	if (code.length() <= 0) return 0;
	std::string str = "";
	bool b = false;
	for (int i = 0; i < code.length(); i++)
	{
		if (b)
			str += code[i];
		if (code[i] == '-') b = true;
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
		return m_codriver;
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
