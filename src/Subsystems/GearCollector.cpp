#include "GearCollector.h"
#include "../RobotMap.h"

GearCollector::GearCollector() :
	Subsystem("Gear Collector")
{
}

GearCollector::~GearCollector()
{
	delete m_intake;
}

void GearCollector::InitDefaultCommand()
{
	//SetDefaultCommand(new MySpecialCommand());
}

void GearCollector::Initialize()
{
	m_intake = new CANTalon(GEAR_INTAKE_PORT);
	m_intake->SetControlMode(CANTalon::ControlMode::kSpeed);
}

void GearCollector::Set(double speed)
{
	m_intake->Set(speed);
}
