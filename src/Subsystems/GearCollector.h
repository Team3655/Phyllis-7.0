#ifndef GEAR_COLLECTOR_H
#define GEAR_COLLECTOR_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include <Preferences.h>

#include "../ExtSubsystem.h"

// Summary:
// 	Gear collector and management system
class GearCollector : public frc::Subsystem, public ExtSubsystem
{
private:
	enum CollectState
	{
		kStopped = 0,
		kCollecting = 1,
		kEjecting = 2
	} m_state;

	CANTalon* m_intake;
	CANTalon* m_transport;

	std::string state_to_string(uint32_t state);

public:
	GearCollector();
	~GearCollector();
	void InitDefaultCommand();

	void Initialize(frc::Preferences* prefs) override;
	void DashboardOutput(bool verbose = false) override;

	// Set all of the motors
	void SetIntake();
	void Stop();
};

#endif  // GEAR_COLLECTOR_H
