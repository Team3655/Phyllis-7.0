#include "GearCollector.h"
#include "../RobotMap.h"

#include "../Commands/CollectGear.h"

GearCollector::GearCollector() :
	Subsystem("Gear Collector")
{
}

GearCollector::~GearCollector()
{
	delete m_intake;
	delete m_transport;
}

void GearCollector::InitDefaultCommand()
{
	SetDefaultCommand(new CollectGear());
}

std::string GearCollector::state_to_string(uint32_t state)
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

void GearCollector::Initialize(frc::Preferences* prefs)
{
	m_intake = new CANTalon(GEAR_INTAKE_PORT);
	m_intake->SetControlMode(CANTalon::ControlMode::kPercentVbus);

	m_transport = new CANTalon(GEAR_TRANS_PORT);
	m_transport->SetControlMode(CANTalon::ControlMode::kPercentVbus);

	m_intakeSpeed = frc::SmartDashboard::GetNumber("gear_intake_speed", GEAR_INTAKE_SPEED);
	m_transSpeed = frc::SmartDashboard::GetNumber("gear_trans_speed", GEAR_TRANS_SPEED);
}

void GearCollector::DashboardOutput(bool verbose)
{
	frc::SmartDashboard::PutString("State", state_to_string(m_state));

	if (verbose)
	{

	}
}

void GearCollector::SetIntake()
{
	m_intake->Set(m_intakeSpeed);
	m_transport->Set(m_transSpeed);
}

void GearCollector::Stop()
{
	m_intake->Set(0);
	m_transport->Set(0);
}
