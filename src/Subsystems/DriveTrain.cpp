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

void DriveTrain::Initialize()
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

	SetTalonMode(CANTalon::TalonControlMode::kSpeedMode);
	set_pid_values();

	//m_rf->SetInverted(true);
	//m_rb->SetInverted(true);

	//m_rb->SetSensorDirection(true);

	m_drive = new RobotDrive(m_lb, m_rb);

	m_shiftState = m_shifter->Get();
}

CANTalon::TalonControlMode DriveTrain::get_talon_mode()
{
	return m_lb->GetTalonControlMode() & m_rb->GetTalonControlMode();
}

void DriveTrain::set_pid_values()
{
	switch (get_talon_mode())
	{
	case CANTalon::TalonControlMode::kPositionMode:
		m_lb->SetPID(DRIVE_LEFT_POS_P, DRIVE_LEFT_POS_I, DRIVE_LEFT_POS_D);
		m_rb->SetPID(DRIVE_RIGHT_POS_P, DRIVE_RIGHT_POS_I, DRIVE_RIGHT_POS_D);
		break;
	default:
	case CANTalon::TalonControlMode::kSpeedMode:
		m_lb->SetPID(DRIVE_LEFT_SPD_P, DRIVE_LEFT_SPD_I, DRIVE_LEFT_SPD_D);
		m_rb->SetPID(DRIVE_RIGHT_SPD_P, DRIVE_RIGHT_SPD_I, DRIVE_RIGHT_SPD_D);
		break;
	}
}

void DriveTrain::SetTalonMode(CANTalon::TalonControlMode mode)
{
	m_lb->SetTalonControlMode(mode);
	m_rb->SetTalonControlMode(mode);

	set_pid_values();
}

void DriveTrain::ArcadeDrive(double move, double rotate)
{
	if (m_reverse)
	{
		move = -move;
		rotate = -rotate;
	}
	m_drive->ArcadeDrive(move * m_scaleFactor * DRIVE_ENC_CPR, rotate * m_scaleFactor * DRIVE_ENC_CPR);
	//std::cout << m_lb->GetEncPosition() << " : " << m_rb->GetEncPosition() << std::endl;
	std::cout << m_rb->IsSensorPresent(CANTalon::CtreMagEncoder_Absolute) << std::endl;
}

void DriveTrain::TankDrive(double left, double right)
{
	if (m_reverse)
	{
		left = -left;
		right = -right;
	}
	m_drive->TankDrive(left, right);
	std::cout << m_lb->GetEncPosition() << "/" << m_lb->Get() << " : " << m_rb->GetEncPosition() << "/" << m_rb->Get() << std::endl;
}

void DriveTrain::Reverse(bool reverse)
{
	m_reverse = reverse;
}

void DriveTrain::Shift()
{
	m_shifter->Set(!m_shiftState);
	m_shiftState = m_shifter->Get();
}

void DriveTrain::SetScale(double scale)
{
	m_scaleFactor = scale;
}

void DriveTrain::SetPosition(double pos)
{
	m_lb->Set(pos);
	m_rb->Set(pos);
	std::cout << m_lb->GetEncPosition() << "/" << m_lb->GetClosedLoopError() << " : " << m_rb->GetEncPosition() << "/" << m_rb->GetClosedLoopError() << std::endl;
}
