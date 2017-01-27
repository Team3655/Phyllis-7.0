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
	m_shifter = new Solenoid(DRIVE_LEFT_SHIFT_PORT);

	m_lb = new CANTalon(DRIVE_LB_PORT);
	m_lb->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	m_lb->SetTalonControlMode(CANTalon::TalonControlMode::kPositionMode);
	m_lb->SetPID(DRIVE_LB_P, DRIVE_LB_I, DRIVE_LB_D);

	m_lf = new CANTalon(DRIVE_LF_PORT);
	m_lf->SetControlMode(CANTalon::ControlMode::kFollower);
	m_lf->Set(m_lb->GetDeviceID());

	m_rb = new CANTalon(DRIVE_RB_PORT);
	m_rb->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	m_rb->SetTalonControlMode(CANTalon::TalonControlMode::kPositionMode);
	m_rb->SetPID(DRIVE_RB_P, DRIVE_RB_I, DRIVE_RB_D);

	m_rf = new CANTalon(DRIVE_RF_PORT);
	m_rf->SetControlMode(CANTalon::ControlMode::kFollower);
	m_rf->Set(m_rb->GetDeviceID());

	m_rf->SetInverted(true);
	m_rb->SetInverted(true);

	m_drive = new RobotDrive(m_lb, m_rb);

	m_shiftState = m_shifter->Get();
}

void DriveTrain::ArcadeDrive(double move, double rotate)
{
	if (m_reverse)
	{
		move = -move;
		rotate = -rotate;
	}
	m_drive->ArcadeDrive(move * m_scaleFactor * DRIVE_ENC_CPR, rotate * m_scaleFactor * DRIVE_ENC_CPR);
	std::cout << m_lb->Get() << m_rb->Get() << std::endl;
}

void DriveTrain::TankDrive(double left, double right)
{
	if (m_reverse)
	{
		left = -left;
		right = -right;
	}
	m_drive->TankDrive(left * m_scaleFactor * DRIVE_ENC_CPR, right * m_scaleFactor * DRIVE_ENC_CPR);
	std::cout << m_lb->Get() << m_rb->Get() << std::endl;
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
	m_scaleFactor = scale * DRIVE_ENC_CPR;
}

void DriveTrain::SetPosition(double pos)
{
	m_lb->Set(pos * DRIVE_ENC_CPR);
	m_rb->Set(pos * DRIVE_ENC_CPR);
	std::cout << m_lb->Get() << m_rb->Get() << std::endl;
}
