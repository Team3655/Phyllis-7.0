#include "Shooter.h"
#include "../RobotMap.h"

#include "../Commands/Shoot.h"

Shooter::Shooter() :
	frc::Subsystem("Shooter")
{
	m_shooter = new CANTalon(SHOOT_MOTOR_PORT);
	m_shooter->SetControlMode(frc::CANSpeedController::kPercentVbus);
	m_shooter->Enable();
}

Shooter::~Shooter()
{
	delete m_shooter;
}

void Shooter::InitDefaultCommand() {
	SetDefaultCommand(new Shoot());
}
