#ifndef Climber_H
#define Climber_H

#include <Commands/Subsystem.h>

class Climber : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Climber();
	void InitDefaultCommand();
};

#endif  // Climber_H
