#ifndef FUEL_COLLECTOR_H
#define FUEL_COLLECTOR_H

#include <Commands/Subsystem.h>
#include <Servo.h>
#include <Ultrasonic.h>
#include <CANTalon.h>

#include "../ExtSubsystem.h"

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

	void SetOpen(bool open);

	// bool IsBallPresent();
};

#endif  // FUEL_COLLECTOR_H
