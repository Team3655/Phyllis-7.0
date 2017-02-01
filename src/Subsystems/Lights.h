#ifndef LIGHTS_H
#define LIGHTS_H

#include <Commands/Subsystem.h>

#include "../ExtSubsystem.h"

class Lights : public Subsystem, public ExtSubsystem
{
private:

public:
	Lights();
	void InitDefaultCommand();

	void Initialize() override;
	void DashboardOutput(bool verbose = false) override;
};

#endif  // LIGHTS_H
