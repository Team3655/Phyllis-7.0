#include "GearCollector.h"
#include "../RobotMap.h"

#include "../Commands/CollectGear.h"

GearCollector::GearCollector() :
	Subsystem("Gear Collector")
{
}

GearCollector::~GearCollector()
{
	m_log->Log(this, Logger::kExit);
	delete m_intake;
	delete m_transportFront;
	delete m_transportBack;
	delete m_gearSensor;
}

void GearCollector::InitDefaultCommand()
{
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
	m_log = Logger::GetInstance();
	m_log->AddLog(this);
	m_log->Log(this, Logger::kEnter);

	m_intake = new CANTalon(GEAR_INTAKE_PORT);
	m_intake->SetControlMode(CANTalon::ControlMode::kPercentVbus);

	m_log->Log(this, Logger::kInfo, "Intake initialized to " + std::to_string(m_intake->GetDeviceID()));

	m_transportBack = new CANTalon(GEAR_TRANS_BACK_PORT);
	m_transportBack->SetControlMode(CANTalon::ControlMode::kPercentVbus);

	m_transportFront = new CANTalon(GEAR_TRANS_FRONT_PORT);
	m_transportFront->SetControlMode(CANTalon::ControlMode::kFollower);
	m_transportFront->Set(m_transportBack->GetDeviceID());

	m_log->Log(this, Logger::kInfo, "Transport master initialized to " + std::to_string(m_transportBack->GetDeviceID()));

	m_intakeSpeed = frc::SmartDashboard::GetNumber("gear_intake_speed", GEAR_INTAKE_SPEED);
	m_transSpeed = frc::SmartDashboard::GetNumber("gear_trans_speed", GEAR_TRANS_SPEED);

	m_gearEjector = new frc::DoubleSolenoid(GEAR_EJECTOR_F_PORT, GEAR_EJECTOR_B_PORT);
	m_log->Log(this, Logger::kInfo, "re-tractor initialized to F:" + std::to_string(GEAR_EJECTOR_F_PORT) + " B: " + std::to_string(GEAR_EJECTOR_B_PORT));

	m_gearSensor = new frc::DigitalInput(GEAR_SENSOR_PORT);
	m_log->Log(this, Logger::kInfo, "Gear Sensor initialized to " + GEAR_SENSOR_PORT);
}

void GearCollector::DashboardOutput(bool verbose)
{
	frc::SmartDashboard::PutString("Gear Collector State", state_to_string(m_state));
	frc::SmartDashboard::PutBoolean("Gear Present", IsGearPresent());
	frc::SmartDashboard::PutBoolean("Gear Intake On", m_intake->Get() > 0.0);

	if (verbose)
	{

	}

	m_log->Log(this, Logger::kInfo, "Gear presence: " + std::to_string(IsGearPresent()));
}

bool GearCollector::IsGearPresent()
{
	return m_gearSensor->Get(); // Defaults to on (true = gear)
}

void GearCollector::SetIntake(int direction)
{
	m_state = CollectState::kCollecting;
	m_intake->Set(m_intakeSpeed * direction);
	m_transportBack->Set(m_transSpeed * direction);
	m_log->Log(this, Logger::kInfo, "Intake set to " + std::to_string(m_intake->Get()));
	m_log->Log(this, Logger::kInfo, "Transport set to " + std::to_string(m_transportBack->Get()));
}

void GearCollector::Stop()
{
	m_state = CollectState::kStopped;
	m_intake->Set(0);
	m_transportBack->Set(0);
	m_log->Log(this, Logger::kInfo, "Intake and Transporter stopped");
}

void GearCollector::Eject(bool eject)
{
	m_gearEjector->Set(eject ? frc::DoubleSolenoid::kForward : frc::DoubleSolenoid::kReverse);
	m_log->Log(this, Logger::kInfo, "Re-tractor set to " + (m_gearEjector->Get() == frc::DoubleSolenoid::kForward) ? "Forward" : "Reverse");
}

bool GearCollector::IsEjected()
{
	return m_gearEjector->Get() == frc::DoubleSolenoid::kForward;
}
