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
	Subsystem("Drive")
{
	m_left = new CANTalon(DRIVE_LEFT_PORT);
	m_right = new CANTalon(DRIVE_RIGHT_PORT);
	m_drive = new RobotDrive(m_left, m_right);
}

DriveTrain::~DriveTrain()
{
	delete m_drive;
}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new Drive());
}

void DriveTrain::ArcadeDrive(double move, double rotate)
{
	m_drive->ArcadeDrive(move, rotate);
}

void DriveTrain::TankDrive(float l, float r)
{
	m_drive->TankDrive(l, r);
}
