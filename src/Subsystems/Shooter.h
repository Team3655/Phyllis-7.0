#ifndef SHOOTER_H
#define SHOOTER_H

#include <Commands/Subsystem.h>
#include <Wpilib.h>
#include <CANTalon.h>

class Shooter : public frc::Subsystem
{
private:
	CANTalon* m_shooter;

public:
	Shooter();
	~Shooter();
	void InitDefaultCommand();

	inline void Set(double value) { m_shooter->Set(value); }

	void DebugInfo()
	{
	}
};

#endif  // SHOOTER_H
