#include "Shooter.h"
#include "../RobotMap.h"

#include "../Commands/Shoot.h"

Shooter::Shooter() :
	frc::Subsystem("Shooter")
{
	m_targetSpeed = 0; // Do some math to find target speed
}

Shooter::~Shooter()
{
	delete m_shooter;
}

void Shooter::InitDefaultCommand()
{
	//SetDefaultCommand(new Shoot());
}

void Shooter::Initialize()
{
	m_shooter = new CANTalon(SHOOT_MOTOR_PORT);
	m_shooter->SetControlMode(frc::CANSpeedController::kPercentVbus);
	m_shooter->Enable();
}

void Shooter::Set(double speed)
{
	m_shooter->Set(speed);
}

bool Shooter::IsAtSpeed()
{
	return is_about(m_shooter->Get(), 50.0);
}
