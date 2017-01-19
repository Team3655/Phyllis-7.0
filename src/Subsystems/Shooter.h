#ifndef SHOOTER_H
#define SHOOTER_H

#include <Commands/Subsystem.h>
#include <Wpilib.h>
#include <CANTalon.h>

class Shooter : public frc::Subsystem
{
private:
	CANTalon* m_shooter;

	double m_targetSpeed;

public:
	Shooter();
	~Shooter();
	void InitDefaultCommand();

	void Set(double speed);

	bool IsAtSpeed();

	void DebugInfo()
	{
	}
};

#endif  // SHOOTER_H
