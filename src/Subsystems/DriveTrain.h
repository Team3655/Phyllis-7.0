///////////////////////////////////////////////////////////////////////////////
//
// DriveTrain.h
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include <Commands/Subsystem.h>
#include <Wpilib.h>
#include <CANTalon.h>

class DriveTrain : public frc::Subsystem
{
private:
	RobotDrive* m_drive;

	CANTalon* m_left;
	CANTalon* m_right;

	bool m_accel;
	double m_targetSpeed;
	double m_currentSpeed;

public:
	const int ENCODER_CPR = 0000;

	DriveTrain();
	~DriveTrain();
	void InitDefaultCommand();

	void ArcadeDrive(double move, double rotate);
	void TankDrive(float l, float r);

	void Accelerate(bool accel) { m_accel = accel; }
	bool IsAcceleration() { return m_accel; }
};

#endif // DRIVE_TRAIN_H
