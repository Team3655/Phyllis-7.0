#include "Shooter.h"
#include "../RobotMap.h"

#include "../Commands/Shoot.h"

Shooter::Shooter() :
	frc::Subsystem("Shooter"), ExtSubsystem()
{
	m_targetSpeed = 0;
}

Shooter::~Shooter()
{
	m_log->StopStreamLog();
	m_log->Log(this, Logger::kExit);
	delete m_shooter;
}

void Shooter::InitDefaultCommand()
{
}

std::string Shooter::state_to_string(uint32_t state)
{
	switch (state)
	{
	case 0:
		return "Stopped";
		break;
	case 1:
		return "Shooting";
		break;
	case 2:
		return "Recovering";
		break;
	default:
		return "Error";
		break;
	}
}

void Shooter::Initialize(frc::Preferences* prefs)
{
	m_log = Logger::GetInstance();
	m_log->AddLog(this);
	m_log->Log(this, Logger::kEnter);
	m_log->StreamLog(this);

	frc::SmartDashboard::PutNumber("Shoot Speed", 0.0);

	m_shooter = new CANTalon(SHOOT_MOTOR_PORT);
	m_shooter->SetFeedbackDevice(CANTalon::FeedbackDevice::CtreMagEncoder_Absolute);
	m_shooter->SetControlMode(frc::CANSpeedController::kSpeed);
	m_shooter->Set(0);
	//m_shooter->SetStatusFrameRateMs(CANTalon::StatusFrameRateFeedback, 100);
	m_log->Log(this, Logger::kInfo, "Shooter initialized to " + std::to_string(m_shooter->GetDeviceID()));

	for (int i = 0; i < 2; i++)
	{
		m_shooter->SelectProfileSlot(i);
		m_shooter->SetPID(
			SHOOT_P,
			SHOOT_I,
			SHOOT_D);
		m_shooter->SetF(SHOOT_F);
		m_shooter->SetAllowableClosedLoopErr(10);
	}

	m_log->Log(this, Logger::kInfo,
		"Shooter P: " + std::to_string(m_shooter->GetP()) +
		" I: " + std::to_string(m_shooter->GetI()) +
		" D: " + std::to_string(m_shooter->GetD()));

	m_shooter->Enable();

	m_shooter->SetSensorDirection(false);
	//m_shooter->SetInverted(true);

	m_targetSpeed = prefs->GetDouble("shoot_speed", SHOOT_SPEED);
}

void Shooter::DashboardOutput(bool verbose)
{
	frc::SmartDashboard::PutString("Shooter State", state_to_string(m_state));
	//frc::SmartDashboard::PutNumber("Shooter Speed", m_shooter->GetEncVel());

	if (verbose)
	{

	}
}

void Shooter::Set(double speed)
{
	m_shooter->Set(-speed);
	m_log->Log(this, Logger::kInfo, "Shooter speed set to " + std::to_string(m_shooter->GetSetpoint()));
}

bool Shooter::IsAtSpeed()
{
	return is_about(m_targetSpeed, m_shooter->Get(), 50.0);
}
