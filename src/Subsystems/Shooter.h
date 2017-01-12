#ifndef SHOOTER_H
#define SHOOTER_H

#include <Commands/Subsystem.h>
#include <Wpilib.h>

class Shooter : public frc::Subsystem {
private:
	Spark* m_shooter;

public:
	Shooter();
	void InitDefaultCommand();

	void Set(double value) { m_shooter->Set(value); }
};

#endif  // SHOOTER_H
