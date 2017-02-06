#ifndef FUEL_COLLECTOR_H
#define FUEL_COLLECTOR_H

#include <Commands/Subsystem.h>
#include <Servo.h>
#include <Ultrasonic.h>
#include <CANTalon.h>
#include <Preferences.h>

#include "../ExtSubsystem.h"

// Summary:
// 	Fuel collector and container (magazine for shooter)
class FuelCollector : public frc::Subsystem, public ExtSubsystem
{
private:
	enum CollectState
	{
		kStopped = 0,
		kCollecting = 1,
		kEjecting = 2
	} m_state;

	frc::Servo* m_gate;
	CANTalon* m_intake;

	std::string state_to_string(uint32_t state);

public:
	FuelCollector();
	~FuelCollector();
	void InitDefaultCommand();

	void Initialize(frc::Preferences* prefs) override;
	void DashboardOutput(bool verbose = false) override;

	// Open/close flow from magazine to shooter
	void SetOpen(bool open);
	bool IsOpen() { return m_gate->Get(); }

	// bool IsBallPresent();

	// Set the motor that collects balls
	void SetIntake(double speed);
};

#endif  // FUEL_COLLECTOR_H
