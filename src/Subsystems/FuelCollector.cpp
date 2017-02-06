#include "FuelCollector.h"
#include "../RobotMap.h"

#include "../Commands/CollectFuel.h"

FuelCollector::FuelCollector() :
	Subsystem("Fuel Collector")
{
}

FuelCollector::~FuelCollector()
{
	delete m_gate;
	delete m_intake;
}

std::string FuelCollector::state_to_string(uint32_t state)
{
	switch (state)
	{
	case 0:
		return "Stopped";
		break;
	case 1:
		return "Collecting";
		break;
	case 2:
		return "Ejecting";
		break;
	default:
		return "Error";
		break;
	}
}

void FuelCollector::InitDefaultCommand()
{
	SetDefaultCommand(new CollectFuel());
}

void FuelCollector::Initialize(frc::Preferences* prefs)
{
	m_gate = new frc::Servo(FUEL_GATE_PORT);

	m_intake = new CANTalon(FUEL_INTAKE_PORT);
	m_intake->SetTalonControlMode(CANTalon::TalonControlMode::kSpeedMode);
	m_intake->SetPID(FUEL_INTAKE_P, FUEL_INTAKE_I, FUEL_INTAKE_D);
}

void FuelCollector::DashboardOutput(bool verbose)
{
	frc::SmartDashboard::PutString("Gate", m_gate->Get() ? "open" : "closed");
	frc::SmartDashboard::PutString("State", state_to_string(m_state));

	if (verbose)
	{

	}
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
