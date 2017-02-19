#include "Climber.h"
#include "../RobotMap.h"

Climber::Climber() :
	Subsystem("Climber")
{
	m_state = ClimbState::kDown;
}

Climber::~Climber()
{
	delete m_climbLeft;
	delete m_climbRight;
}

void Climber::InitDefaultCommand()
{
	//SetDefaultCommand(new MySpecialCommand());
}

void Climber::Initialize(frc::Preferences* prefs)
{
	m_climbLeft = new CANTalon(CLIMB_LEFT_PORT);
	m_climbLeft->SetControlMode(CANTalon::ControlMode::kPercentVbus);
	m_climbRight = new CANTalon(CLIMB_RIGHT_PORT);
	m_climbRight->SetControlMode(CANTalon::ControlMode::kFollower);
	m_climbRight->Set(m_climbLeft->GetDeviceID());
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
	frc::SmartDashboard::PutString("State", state_to_string(m_state));

	if (verbose)
	{
		frc::SmartDashboard::PutNumber("Position L", m_climbLeft->GetEncPosition());
		frc::SmartDashboard::PutNumber("Position R", m_climbRight->GetEncPosition());
	}
}

void Climber::SetSpeed(double speed)
{
	m_climbLeft->Set(-speed);
}
