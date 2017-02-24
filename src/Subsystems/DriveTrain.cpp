///////////////////////////////////////////////////////////////////////////////
//
// DriveTrain.cpp
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"
#include <iostream>

DriveTrain::DriveTrain() :
	frc::Subsystem("Drive")
{
	m_lw = frc::LiveWindow::GetInstance();
}

DriveTrain::~DriveTrain()
{
	delete m_shifter;
	delete m_drive;
	delete m_lf;
	delete m_lb;
	delete m_rf;
	delete m_rb;
}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new Drive());
}

void DriveTrain::Initialize(frc::Preferences* prefs)
{
	m_shifter = new Solenoid(DRIVE_SHIFT_PORT);

	m_lb = new CANTalon(DRIVE_LEFT_PORT);
	m_lb->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);

	m_lf = new CANTalon(DRIVE_LF_PORT);
	m_lf->SetControlMode(CANTalon::ControlMode::kFollower);
	m_lf->Set(m_lb->GetDeviceID());

	m_rb = new CANTalon(DRIVE_RIGHT_PORT);
	m_rb->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);

	m_rf = new CANTalon(DRIVE_RF_PORT);
	m_rf->SetControlMode(CANTalon::ControlMode::kFollower);
	m_rf->Set(m_rb->GetDeviceID());

	SetTalonMode(CANTalon::ControlMode::kPercentVbus);
	set_pid_values();

	//m_rf->SetInverted(true);
	//m_rb->SetInverted(true);

	//m_rb->SetSensorDirection(true);

	m_drive = new RobotDrive(m_lb, m_rb);

	m_shiftState = m_shifter->Get();
}

void DriveTrain::DashboardOutput(bool verbose)
{
	frc::SmartDashboard::PutString("Gear", m_shiftState ? "High" : "Low");

	if (verbose)
	{
		frc::SmartDashboard::PutNumber("Count L", m_lb->GetEncVel());
		frc::SmartDashboard::PutNumber("Count R", m_rb->GetEncVel());

		frc::SmartDashboard::PutNumber("Pre L", m_lb->Get());
		frc::SmartDashboard::PutNumber("Pre R", m_rb->Get());
	}
}

CANTalon::TalonControlMode DriveTrain::get_talon_mode()
{
	return (CANTalon::TalonControlMode)(m_lb->GetTalonControlMode() & m_rb->GetTalonControlMode());
}

void DriveTrain::set_pid_values()
{
	switch (CANTalon::TalonControlMode::kSpeedMode)
	{
	case CANTalon::TalonControlMode::kPositionMode:
		m_lb->SetPID(
				frc::SmartDashboard::GetNumber("drive_left_pos_p", DRIVE_LEFT_POS_P),
				frc::SmartDashboard::GetNumber("drive_left_pos_i", DRIVE_LEFT_POS_I),
				frc::SmartDashboard::GetNumber("drive_left_pos_d", DRIVE_LEFT_POS_D));
		m_rb->SetPID(
				frc::SmartDashboard::GetNumber("drive_right_pos_p", DRIVE_RIGHT_POS_P),
				frc::SmartDashboard::GetNumber("drive_right_pos_i", DRIVE_RIGHT_POS_I),
				frc::SmartDashboard::GetNumber("drive_right_pos_d", DRIVE_RIGHT_POS_D));
		break;
	default:
	case CANTalon::TalonControlMode::kSpeedMode:
		m_lb->SetPID(
				frc::SmartDashboard::GetNumber("drive_left_spd_p", DRIVE_LEFT_POS_P),
				frc::SmartDashboard::GetNumber("drive_left_spd_i", DRIVE_LEFT_POS_I),
				frc::SmartDashboard::GetNumber("drive_left_spd_d", DRIVE_LEFT_POS_D));
		m_rb->SetPID(
				frc::SmartDashboard::GetNumber("drive_right_spd_p", DRIVE_RIGHT_POS_P),
				frc::SmartDashboard::GetNumber("drive_right_spd_i", DRIVE_RIGHT_POS_I),
				frc::SmartDashboard::GetNumber("drive_right_spd_d", DRIVE_RIGHT_POS_D));
		break;
	}
}

void DriveTrain::SetTalonMode(uint32_t mode)
{
	//m_lb->SetTalonControlMode((CANTalon::TalonControlMode)mode);
	//m_rb->SetTalonControlMode((CANTalon::TalonControlMode)mode);

	m_lb->SetControlMode((CANTalon::ControlMode)mode);
	m_rb->SetControlMode((CANTalon::ControlMode)mode);

	set_pid_values();
}

void DriveTrain::ArcadeDrive(double move, double rotate)
{
	if (m_disabled) return;
	if (m_reverse)
	{
		move = -move;
		rotate = -rotate;
	}
	m_drive->ArcadeDrive(move, rotate /** m_shifter->Get() ? 0.5 : 1.0*/);
}

void DriveTrain::TankDrive(double left, double right)
{
	if (m_disabled) return;
	if (m_reverse)
	{
		left = -left;
		right = -right;
	}
	m_drive->TankDrive(left, right);
}

void DriveTrain::Reverse()
{
	m_reverse = !m_reverse;
	m_lb->SetInverted(m_reverse);
}

void DriveTrain::Shift()
{
	if (m_disabled) return;
	m_shifter->Set(!m_shiftState);
	m_shiftState = m_shifter->Get();
	//m_scaleFactor = m_shiftState ? 0.5 : 1.0;
}

void DriveTrain::SetScale(double scale)
{
	m_scaleFactor = scale;
}

double DriveTrain::GetScale()
{
	return m_scaleFactor;
}

void DriveTrain::SetPosition(double pos)
{
	if (m_disabled) return;
	m_lb->Set(pos);
	m_rb->Set(-pos);
}

void DriveTrain::GetPosition(double& lPos, double& rPos)
{
	lPos = m_lb->GetEncPosition();
	rPos = m_rb->GetEncPosition();
}

double DriveTrain::GetVelocity()
{
	return (m_lb->GetEncVel() + m_rb->GetEncVel()) / 2;
}
