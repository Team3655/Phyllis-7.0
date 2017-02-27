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
#include <Preferences.h>

#include "../ExtSubsystem.h"

class MotionControl;

// Summary:
//	Class to manage the drive base of the robot
class DriveTrain : public frc::Subsystem, public ExtSubsystem
{
	friend MotionControl;

private:
	frc::RobotDrive* m_drive;

	// Slaves
	CANTalon* m_lf;
	CANTalon* m_rf;
	// Masters
	CANTalon* m_lb;
	CANTalon* m_rb;

	frc::Solenoid* m_shifter;
	bool m_shiftState;

	double m_scaleFactor = 1.0;

	bool m_reverse = false;
	bool m_disabled = false;

	frc::LiveWindow* m_lw;

	CANTalon::TalonControlMode get_talon_mode();
	void set_pid_values();

public:
	DriveTrain();
	~DriveTrain();
	void InitDefaultCommand();

	void Initialize(frc::Preferences* prefs) override;
	void DashboardOutput(bool verbose = false) override;

	void SetTalonMode(CANSpeedController::ControlMode mode);

	// Drive the bot in Arcade Drive (invert doesn't work)
	void ArcadeDrive(double move, double rotate);

	// Drive the bot in Tank Drive
	void TankDrive(double left, double right);

	// Sets which side is the front of the robot
	void Reverse();
	bool IsReversed() { return m_reverse; }

	// Enables/Disables robot so no error can happen
	// Example uses: when shooting or in motion profile mode
	void Disable() { m_disabled = true; }
	void Enable() { m_disabled = false; }

	// Toggles high/low gear
	void Shift();

	void SetScale(double scale);
	double GetScale();

	void SetPosition(double pos);
	void GetPosition(double& lPos, double& rPos);
	double GetVelocity();
};

#endif // DRIVE_TRAIN_H
