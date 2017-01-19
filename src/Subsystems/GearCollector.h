#ifndef GEAR_COLLECTOR_H
#define GEAR_COLLECTOR_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>

class GearCollector : public frc::Subsystem
{
private:
	CANTalon* m_intake;

public:
	GearCollector();
	void InitDefaultCommand();

	void Set(double speed);
};

#endif  // GEAR_COLLECTOR_H
