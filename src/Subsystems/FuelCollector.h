#ifndef FUEL_COLLECTOR_H
#define FUEL_COLLECTOR_H

#include <Commands/Subsystem.h>
#include <Servo.h>
#include <Ultrasonic.h>
#include <CANTalon.h>

#include "../ExtSubsystem.h"

// Summary:
// 	Fuel collector and container (magazine for shooter)
class FuelCollector : public frc::Subsystem, public ExtSubsystem
{
private:
	frc::Servo* m_gate;
	CANTalon* m_intake;

public:
	FuelCollector();
	~FuelCollector();
	void InitDefaultCommand();

	void Initialize() override;

	// Open/close flow from magazine to shooter
	void SetOpen(bool open);

	// bool IsBallPresent();

	// Set the motor that collects balls
	void SetIntake(double speed);
};

#endif  // FUEL_COLLECTOR_H
