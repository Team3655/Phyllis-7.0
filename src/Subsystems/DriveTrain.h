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

	CANTalon* m_lf;
	CANTalon* m_lb;
	CANTalon* m_rf;
	CANTalon* m_rb;

	Solenoid* m_shifter;
	bool m_shiftState;

	double m_targetSpeed = 0;

	bool m_reverse = false;

public:
	DriveTrain();
	~DriveTrain();
	void InitDefaultCommand();

	void ArcadeDrive(double move, double rotate);
	void TankDrive(double left, double right);

	void Reverse(bool reverse);
	bool IsReversed() { return m_reverse; }

	void Shift();
};

#endif // DRIVE_TRAIN_H
