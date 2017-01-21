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
#include <RobotDrive.h>
#include <CANTalon.h>
#include <Solenoid.h>

#include "../ExtSubsystem.h"

// Summary:
//
class DriveTrain : public frc::Subsystem, public ExtSubsystem
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

	void Initialize() override;

	void ArcadeDrive(double move, double rotate);
	void TankDrive(double left, double right);

	void Reverse(bool reverse);
	bool IsReversed() { return m_reverse; }

	void Shift();
};

#endif // DRIVE_TRAIN_H
