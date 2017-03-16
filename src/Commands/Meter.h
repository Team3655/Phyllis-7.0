#ifndef Meter_H
#define Meter_H

#include "Commands/InstantCommand.h"
#include "../CommandBase.h"

class Meter : public frc::InstantCommand {
public:
	Meter();
	void Initialize();
};

#endif  // Meter_H
