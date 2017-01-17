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
	m_left = new CANTalon(DRIVE_LEFT_PORT);
	m_left->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	m_left->SetCloseLoopRampRate(1);

	m_right = new CANTalon(DRIVE_RIGHT_PORT);
	m_right->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	m_right->SetCloseLoopRampRate(1);

	m_drive = new RobotDrive(m_left, m_right);
}

DriveTrain::~DriveTrain()
{
	delete m_drive;
	delete m_left;
	delete m_right;
}

void DriveTrain::InitDefaultCommand()
{
	//SetDefaultCommand(new Drive());
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
