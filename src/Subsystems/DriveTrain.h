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

class DriveTrain : public Subsystem
{
private:
	RobotDrive* m_drive;

	CANTalon* m_left;
	CANTalon* m_right;

public:
	DriveTrain();
	~DriveTrain();
	void InitDefaultCommand();

	void ArcadeDrive(double move, double rotate);
	void TankDrive(float l, float r);
};

#endif // DRIVE_TRAIN_H
