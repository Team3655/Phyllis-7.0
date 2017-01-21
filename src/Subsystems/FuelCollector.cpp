#include "FuelCollector.h"
#include "../RobotMap.h"

FuelCollector::FuelCollector() :
	Subsystem("ExampleSubsystem")
{
}

FuelCollector::~FuelCollector()
{
	delete m_gate;
	delete m_intake;
}


void FuelCollector::InitDefaultCommand()
{
	//SetDefaultCommand(new MySpecialCommand());
}

void FuelCollector::Initialize()
{
	m_gate = new frc::Servo(FUEL_GATE_PORT);
	m_intake = new CANTalon(0);
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
