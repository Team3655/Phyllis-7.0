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
	m_climbLeft->SetControlMode(CANTalon::ControlMode::kPosition);
	m_climbLeft->SetPID()
	m_climbRight = new CANTalon(CLIMB_RIGHT_PORT);
}
