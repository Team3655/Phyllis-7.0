#ifndef EJECT_GEAR_H
#define EJECT_GEAR_H

#include "../CommandBase.h"
#include "Commands/InstantCommand.h"

class EjectGear : public frc::InstantCommand
{
public:
	EjectGear();
	void Initialize();
};

#endif  // EJECT_GEAR_H
