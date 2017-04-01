#include "Climber.h"
#include "../RobotMap.h"

Climber::Climber() :
	frc::Subsystem("Climber"), ExtSubsystem()
{
}

Climber::~Climber()
{
	m_log->Log(this, Logger::kExit);
	delete m_climbLeft;
	delete m_climbRight;
}

void Climber::InitDefaultCommand()
{
}

void Climber::Initialize(frc::Preferences* prefs)
{
	m_log = Logger::GetInstance();
	m_log->AddLog(this);
	m_log->Log(this, Logger::kEnter);

	m_climbLeft = new CANTalon(CLIMB_LEFT_PORT);
	m_climbLeft->SetControlMode(CANTalon::ControlMode::kPercentVbus);
	m_climbRight = new CANTalon(CLIMB_RIGHT_PORT);
	m_climbRight->SetControlMode(CANTalon::ControlMode::kFollower);
	m_climbRight->Set(m_climbLeft->GetDeviceID());

	m_log->Log(this, Logger::kInfo, "Climber Master ID: " + std::to_string(m_climbLeft->GetDeviceID()));
}

std::string Climber::state_to_string(uint32_t state)
{
	switch (state)
	{
	case 0:
		return "Down";
		break;
	case 1:
		return "Transition";
		break;
	case 2:
		return "Up";
		break;
	default:
		return "Error";
		break;
	}
}

void Climber::DashboardOutput(bool verbose)
{
	frc::SmartDashboard::PutBoolean("Climbing", !!m_climbLeft->Get());

	if (verbose)
	{
		frc::SmartDashboard::PutNumber("Climb Left", m_climbLeft->Get());
		frc::SmartDashboard::PutNumber("Climb Left", m_climbRight->Get());
	}
}

void Climber::SetSpeed(double speed)
{
	m_climbLeft->Set(-speed);
	m_log->Log(this, Logger::kInfo, "Climb speed set to " + std::to_string(speed));
}
