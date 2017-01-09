#include "OI.h"
#include "RobotMap.h"

#include <WPILib.h>

OI::OI() :
	m_driver(new Joystick(JOY_DRIVER_PORT)),
	m_coDriver(new Joystick(JOY_CODRIVER_PORT))
{
	// Process operator interface input here.
}
