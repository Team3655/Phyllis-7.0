#ifndef GEAR_COLLECTOR_H
#define GEAR_COLLECTOR_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>

#include "../ExtSubsystem.h"

// Summary:
// 	Gear collector and management system
class GearCollector : public frc::Subsystem, public ExtSubsystem
{
private:
	CANTalon* m_intake;

public:
	GearCollector();
	~GearCollector();
	void InitDefaultCommand();

	void Initialize() override;

	// Set the gear intake motor
	void SetIntake(double speed);
};

#endif  // GEAR_COLLECTOR_H
