#ifndef SHOOTER_H
#define SHOOTER_H

#include <Commands/Subsystem.h>
#include <Wpilib.h>
#include <CANTalon.h>

#include "../ExtSubsystem.h"

// Summary:
//	Class for managing the fuel launcher
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

	// Sets the speed of the shooter motor
	void Set(double speed);

	// Returns whether the motor is at the target speed
	bool IsAtSpeed();
};

#endif  // SHOOTER_H
