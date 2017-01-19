#include "FuelCollector.h"
#include "../RobotMap.h"

FuelCollector::FuelCollector() :
	Subsystem("ExampleSubsystem")
{
	m_gate = new frc::Servo(FUEL_GATE_PORT);
}

void FuelCollector::InitDefaultCommand()
{
	//SetDefaultCommand(new MySpecialCommand());
}

void FuelCollector::SetOpen(bool open)
{
	if (open)
	{
		m_gate->Set(0.0);
	}
	else
	{
		m_gate->Set(100.0);
	}
}
