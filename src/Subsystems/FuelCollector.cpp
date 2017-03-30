#include "FuelCollector.h"
#include "../RobotMap.h"

#include "../Commands/CollectFuel.h"

FuelCollector::FuelCollector() :
	Subsystem("Fuel Collector")
{
}

FuelCollector::~FuelCollector()
{
	m_log->Log(this, Logger::kExit);
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
	m_log = Logger::GetInstance();
	m_log->AddLog(this);
	m_log->Log(this, Logger::kEnter);

	m_intake = new CANTalon(FUEL_INTAKE_PORT);
	m_intake->SetControlMode(CANTalon::ControlMode::kPercentVbus);
	m_log->Log(this, Logger::kInfo, "Intake initialized to " + std::to_string(m_intake->GetDeviceID()));

	m_state = CollectState::kStopped;

	m_meter = new frc::DoubleSolenoid(FUEL_METER_F_PORT, FUEL_METER_B_PORT);
	m_log->Log(this, Logger::kInfo, "Meter initialized to F:" + std::to_string(FUEL_METER_F_PORT) + " B: " + std::to_string(FUEL_METER_B_PORT));
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
	m_log->Log(this, Logger::kInfo, "Intake speed set to " + std::to_string(speed));
}

void FuelCollector::Index(bool index)
{
	m_meter->Set(index ? frc::DoubleSolenoid::kForward : frc::DoubleSolenoid::kReverse);
	m_log->Log(this, Logger::kInfo, "Index set to " + (m_meter->Get() == frc::DoubleSolenoid::kForward) ? "Forward" : "Reverse");
}
