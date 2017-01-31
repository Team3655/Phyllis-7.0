#include "Climber.h"
#include "../RobotMap.h"

Climber::Climber() :
	Subsystem("Climber")
{

}

Climber::~Climber()
{

}

void Climber::InitDefaultCommand()
{
	//SetDefaultCommand(new MySpecialCommand());
}

void Climber::Initialize()
{
	m_climbLeft = new CANTalon(CLIMB_LEFT_PORT);
	m_climbLeft->SetTalonControlMode(CANTalon::TalonControlMode::kPositionMode);
	m_climbLeft->SetPID(CLIMB_LEFT_P, CLIMB_LEFT_I, CLIMB_LEFT_D);
	//m_climbLeft->SetPID()
	m_climbRight = new CANTalon(CLIMB_RIGHT_PORT);
	m_climbRight->SetTalonControlMode(CANTalon::TalonControlMode::kPositionMode);
	m_climbRight->SetPID(CLIMB_RIGHT_P, CLIMB_RIGHT_I, CLIMB_RIGHT_D);
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
