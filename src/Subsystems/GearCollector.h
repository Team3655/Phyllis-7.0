#ifndef GEAR_COLLECTOR_H
#define GEAR_COLLECTOR_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>

#include "../ExtSubsystem.h"

class GearCollector : public frc::Subsystem, public ExtSubsystem
{
private:
	CANTalon* m_intake;

public:
	GearCollector();
	~GearCollector();
	void InitDefaultCommand();

	void Initialize() override;

	void Set(double speed);
};

#endif  // GEAR_COLLECTOR_H
