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

DriveTrain::DriveTrain() :
	frc::Subsystem("Drive")
{
	m_shifter = new Solenoid(DRIVE_LEFT_SHIFT_PORT);

	m_lf = new CANTalon(DRIVE_LF_PORT);
	m_lf->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	m_lf->SetPID(DRIVE_LF_P, DRIVE_LF_I, DRIVE_LF_D);
	m_lf->SetCloseLoopRampRate(1);
	m_lb = new CANTalon(DRIVE_LB_PORT);
	m_lb->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	m_lb->SetPID(DRIVE_LB_P, DRIVE_LB_I, DRIVE_LB_D);
	m_lb->SetCloseLoopRampRate(1);

	m_rf = new CANTalon(DRIVE_RF_PORT);
	m_rf->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	m_rf->SetPID(DRIVE_RF_P, DRIVE_RF_I, DRIVE_RF_D);
	m_rf->SetCloseLoopRampRate(1);
	m_rb = new CANTalon(DRIVE_RB_PORT);
	m_rb->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	m_rb->SetPID(DRIVE_RB_P, DRIVE_RB_I, DRIVE_RB_D);
	m_rb->SetCloseLoopRampRate(1);

	m_drive = new RobotDrive(m_lf, m_lb, m_rf, m_rb);

	m_shiftState = m_shifter->Get();
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

void DriveTrain::ArcadeDrive(double move, double rotate)
{
	if (m_reverse)
	{
		move = -move;
		rotate = -rotate;
	}
	m_drive->ArcadeDrive(move, rotate);
}

void DriveTrain::TankDrive(double left, double right)
{
	if (m_reverse)
	{
		left = -left;
		right = -right;
	}
	m_drive->TankDrive(left, right);
}

void DriveTrain::Reverse(bool reverse)
{
	m_reverse = reverse;
	m_targetSpeed = -m_targetSpeed;
}

void DriveTrain::Shift()
{
	m_shifter->Set(!m_shiftState);
	m_shiftState = m_shifter->Get();
}
