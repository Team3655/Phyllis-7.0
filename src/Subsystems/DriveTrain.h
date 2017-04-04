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
#include <DoubleSolenoid.h>
#include <Preferences.h>
#include <Relay.h>

#include "../ExtSubsystem.h"
#include "Logger.h"

#define HIGH frc::DoubleSolenoid::Value::kForward
#define LOW frc::DoubleSolenoid::Value::kReverse

class MagicDrive;

// Summary:
//	Class to manage the drive base of the robot
class DriveTrain : public frc::Subsystem, public ExtSubsystem
{
	friend MagicDrive;

private:
	// Slaves
	CANTalon* m_lf;
	CANTalon* m_rf;
	// Masters
	CANTalon* m_lb;
	CANTalon* m_rb;

	frc::DoubleSolenoid* m_shifter;
	bool m_shiftState;

	double m_scaleFactor = 1.0;

	bool m_reverse = false;
	bool m_disabled = false;

	frc::LiveWindow* m_lw;

	Logger* m_log;

	void set_pid_values();

public:
	DriveTrain();
	~DriveTrain();
	void InitDefaultCommand();

	void Initialize(frc::Preferences* prefs) override;
	void DashboardOutput(bool verbose = false) override;

	void SetTalonMode(CANTalon::TalonControlMode mode);
	CANTalon::TalonControlMode GetTalonMode();

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

	// Shifter
	void Shift();

	void SetScale(double scale);
	double GetScale();

	void GetPosition(double& lPos, double& rPos);
	double GetVelocity();

	// Resets the encoder position for the drive talons
	void ResetEnc();
};

#endif // DRIVE_TRAIN_H
