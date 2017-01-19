#ifndef FUEL_COLLECTOR_H
#define FUEL_COLLECTOR_H

#include <Commands/Subsystem.h>
#include <Servo.h>
#include <Ultrasonic.h>

class FuelCollector : public frc::Subsystem
{
private:
	frc::Servo* m_gate;

public:
	FuelCollector();
	void InitDefaultCommand();

	void SetOpen(bool open);

	// bool IsBallPresent();
};

#endif  // FUEL_COLLECTOR_H
