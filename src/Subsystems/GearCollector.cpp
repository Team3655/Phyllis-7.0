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
}

void GearCollector::InitDefaultCommand()
{
	SetDefaultCommand(new CollectGear());
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

void GearCollector::Initialize()
{
	m_intake = new CANTalon(GEAR_INTAKE_PORT);
	m_intake->SetControlMode(CANTalon::ControlMode::kSpeed);
}

void GearCollector::DashboardOutput(bool verbose)
{
	frc::SmartDashboard::PutString("State", state_to_string(m_state));

	if (verbose)
	{

	}
}

void GearCollector::SetIntake(double speed)
{
	m_intake->Set(speed);
}
