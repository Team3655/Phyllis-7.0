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

	m_intake = new CANTalon(FUEL_INTAKE_PORT);
	m_intake->SetControlMode(CANTalon::ControlMode::kSpeed);
	m_intake->SetPID(FUEL_INTAKE_P, FUEL_INTAKE_I, FUEL_INTAKE_D);
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

void FuelCollector::SetIntake(double speed)
{
	m_intake->Set(speed);
}
