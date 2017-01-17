#include "GearCollector.h"
#include "../RobotMap.h"

GearCollector::GearCollector() :
	Subsystem("Gear Collector")
{
	m_intake = new CANTalon(GEAR_INTAKE_PORT);
}

void GearCollector::InitDefaultCommand()
{
	//SetDefaultCommand(new MySpecialCommand());
}
