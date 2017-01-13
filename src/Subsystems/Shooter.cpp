#include "Shooter.h"
#include "../RobotMap.h"

#include "../Commands/Shoot.h"

Shooter::Shooter() :
	frc::Subsystem("Shooter")
{
	m_shooter = new Spark(0);
}

Shooter::~Shooter()
{
	delete m_shooter;
}

void Shooter::InitDefaultCommand() {
	SetDefaultCommand(new Shoot());
}
