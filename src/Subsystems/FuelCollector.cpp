#include "FuelCollector.h"
#include "../RobotMap.h"

#include "../Commands/CollectFuel.h"

FuelCollector::FuelCollector() :
	Subsystem("Fuel Collector")
{
}

FuelCollector::~FuelCollector()
{
	delete m_meter;
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
}

void FuelCollector::Initialize(frc::Preferences* prefs)
{
	m_meter = new frc::Servo(FUEL_METER_PORT);

	m_intake = new CANTalon(FUEL_INTAKE_PORT);
	m_intake->SetControlMode(CANTalon::ControlMode::kPercentVbus);

	m_state = CollectState::kStopped;

	m_meter->Set(0);
}

void FuelCollector::DashboardOutput(bool verbose)
{
	frc::SmartDashboard::PutString("Fuel Collector State", state_to_string(m_state));
	frc::SmartDashboard::PutBoolean("Fuel Intake On", m_intake->Get() > 0.0);
	frc::SmartDashboard::PutBoolean("Meter On", !!m_meter->Get());

	if (verbose)
	{

	}
}

void FuelCollector::SetIntake(double speed)
{
	m_intake->Set(speed);
}

void FuelCollector::Index(double angle)
{
	m_meter->SetAngle(angle);
}
