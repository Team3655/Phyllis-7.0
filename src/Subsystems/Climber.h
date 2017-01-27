#ifndef Climber_H
#define Climber_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>

#include "../ExtSubsystem.h"

// Summary:
//
class Climber : public frc::Subsystem, public ExtSubsystem
{
private:
	CANTalon* m_climbLeft;
	CANTalon* m_climbRight;

public:
	Climber();
	~Climber();
	void InitDefaultCommand();

	void Initialize() override;
};

#endif  // Climber_H
