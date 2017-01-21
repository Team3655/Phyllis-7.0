#ifndef SHOOTER_H
#define SHOOTER_H

#include <Commands/Subsystem.h>
#include <Wpilib.h>
#include <CANTalon.h>

#include "../ExtSubsystem.h"

class Shooter : public frc::Subsystem, public ExtSubsystem
{
private:
	CANTalon* m_shooter;

	double m_targetSpeed;

public:
	Shooter();
	~Shooter();
	void InitDefaultCommand();

	void Initialize() override;

	void Set(double speed);

	bool IsAtSpeed();
};

#endif  // SHOOTER_H
