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
	m_shoot = new JoystickButton(m_driver, 0);
	m_shoot->WhenActive(new Shoot());

	m_shift = new JoystickButton(m_driver, 2);
	m_shift->WhenPressed(new Shift());
}

OI::~OI()
{
	delete m_driver;
	delete m_coDriver;
	delete m_shoot;
	delete m_shift;
}
