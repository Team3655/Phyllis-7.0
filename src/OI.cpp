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

#include <WPILib.h>
#include "Commands/Shoot.h"
#include "Commands/Shift.h"

OI::OI() :
	m_driver(new Joystick(JOY_DRIVER_PORT)),
	m_coDriver(new Joystick(JOY_CODRIVER_PORT))
{
	//m_shoot = new JoystickButton(m_driver, 1);
	//m_shoot->WhenPressed(new Shoot());

	m_shift = new JoystickButton(m_driver, 4);
	m_shift->WhenPressed(new Shift());
}

OI::~OI()
{
	delete m_driver;
	delete m_coDriver;
	delete m_shoot;
	delete m_shift;
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
