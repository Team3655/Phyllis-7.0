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
	//SetDefaultCommand(new CollectFuel());
}

void FuelCollector::Initialize(frc::Preferences* prefs)
{
	m_meter = new CANTalon(FUEL_METER_PORT);
	m_meter->SetControlMode(CANTalon::ControlMode::kPercentVbus);
	m_meter->SetPID(
			prefs->GetDouble("fuel_meter_p", FUEL_METER_P),
			prefs->GetDouble("fuel_meter_i", FUEL_METER_I),
			prefs->GetDouble("fuel_meter_d", FUEL_METER_D));

	//m_meter->Reset();
	m_currentMeterPos = 0;

	m_intake = new CANTalon(FUEL_INTAKE_PORT);
	m_intake->SetTalonControlMode(CANTalon::TalonControlMode::kSpeedMode);
	m_intake->SetPID(
			prefs->GetDouble("fuel_intake_p", FUEL_INTAKE_P),
			prefs->GetDouble("fuel_intake_i", FUEL_INTAKE_I),
			prefs->GetDouble("fuel_intake_d", FUEL_INTAKE_D));

	m_state = CollectState::kStopped;
}

void FuelCollector::DashboardOutput(bool verbose)
{
	frc::SmartDashboard::PutString("State", state_to_string(m_state));
	frc::SmartDashboard::PutNumber("Balls Indexed", m_currentMeterPos / (FUEL_METER_CPR / FUEL_BALL_PER_TURN));

	if (verbose)
	{
		frc::SmartDashboard::PutNumber("Meter Count", m_meter->GetEncPosition());
	}
}

void FuelCollector::IndexOne()
{
	m_currentMeterPos += FUEL_BALL_PER_TURN;
	m_meter->Set(m_currentMeterPos);
}

void FuelCollector::SetIntake(double speed)
{
	m_intake->Set(speed);
}

void FuelCollector::Index(double speed)
{
	m_meter->Set(-speed);
}
