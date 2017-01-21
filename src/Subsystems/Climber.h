#ifndef Climber_H
#define Climber_H

#include <Commands/Subsystem.h>

#include "../ExtSubsystem.h"

class Climber : public frc::Subsystem, public ExtSubsystem
{
private:

public:
	Climber();
	~Climber();
	void InitDefaultCommand();

	void Initialize() override;
};

#endif  // Climber_H
