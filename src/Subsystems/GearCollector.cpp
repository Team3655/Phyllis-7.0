#include "GearCollector.h"
#include "../RobotMap.h"

#include "../Commands/CollectGear.h"

GearCollector::GearCollector() :
	Subsystem("Gear Collector")
{

}

GearCollector::~GearCollector()
{
	m_polling = false;
	delete m_intake;
	delete m_transportFront;
	delete m_transportBack;
}

void GearCollector::InitDefaultCommand()
{
	//SetDefaultCommand(new CollectGear());
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

	m_transportBack = new CANTalon(GEAR_TRANS_BACK_PORT);
	m_transportBack->SetControlMode(CANTalon::ControlMode::kPercentVbus);

	// Currently only one talon
	//m_transportFront = new CANTalon(GEAR_TRANS_FRONT_PORT);
	//m_transportFront->SetControlMode(CANTalon::ControlMode::kFollower);
	//m_transportFront->Set(m_transportBack->GetDeviceID());

	m_intakeSpeed = frc::SmartDashboard::GetNumber("gear_intake_speed", GEAR_INTAKE_SPEED);
	m_transSpeed = frc::SmartDashboard::GetNumber("gear_trans_speed", GEAR_TRANS_SPEED);

	m_pollLock = new std::mutex();
	m_gearPoll = new std::thread(&GearCollector::gear_poller, this);
}

void GearCollector::DashboardOutput(bool verbose)
{
	frc::SmartDashboard::PutString("State", state_to_string(m_state));

	if (verbose)
	{

	}
}

void GearCollector::gear_poller()
{
	while (true)
	{
		m_pollLock->lock();
		m_wasPresent = m_isPresent;
		m_isPresent = false; // Check if present
		m_pollLock->unlock();

		if (!m_polling)
			break;
		sleep(100);
	}
}

bool GearCollector::IsGearPresent()
{
	return false; // Not implemented
}

void GearCollector::SetIntake(int direction)
{
	m_intake->Set(m_intakeSpeed * direction);
	m_transportBack->Set(m_transSpeed * direction);
}

void GearCollector::Stop()
{
	m_intake->Set(0);
	m_transportBack->Set(0);
}
