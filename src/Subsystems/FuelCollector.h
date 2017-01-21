#ifndef FUEL_COLLECTOR_H
#define FUEL_COLLECTOR_H

#include <Commands/Subsystem.h>
#include <Servo.h>
#include <Ultrasonic.h>
#include <CANTalon.h>

class FuelCollector : public frc::Subsystem
{
private:
	//frc::Servo* m_gate;
	//CANTalon* m_intake;

public:
	FuelCollector();
	void InitDefaultCommand();

	void SetOpen(bool open);

	// bool IsBallPresent();
};

#endif  // FUEL_COLLECTOR_H
