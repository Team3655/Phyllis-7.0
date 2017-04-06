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
	frc::Subsystem("Drive"), ExtSubsystem()
{
	m_lw = frc::LiveWindow::GetInstance();
}

DriveTrain::~DriveTrain()
{
	m_log->Log(this, Logger::kExit);
	delete m_shifter;
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
	m_log = Logger::GetInstance();
	m_log->AddLog(this);
	m_log->Log(this, Logger::kEnter);

	m_shifter = new frc::DoubleSolenoid(DRIVE_SHIFT_HIGH_PORT, DRIVE_SHIFT_LOW_PORT);
	m_log->Log(this, Logger::kInfo, "Shifter Solenoid F: " + std::to_string(DRIVE_SHIFT_HIGH_PORT) +
			" B: " + std::to_string(DRIVE_SHIFT_LOW_PORT));

	m_lb = new CANTalon(DRIVE_LEFT_PORT);
	m_lb->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	m_lb->ConfigEncoderCodesPerRev(100);

	m_lf = new CANTalon(DRIVE_LF_PORT);
	m_lf->SetControlMode(frc::CANSpeedController::kFollower);
	m_lf->Set(m_lb->GetDeviceID());

	m_rb = new CANTalon(DRIVE_RIGHT_PORT);
	m_rb->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	m_rb->ConfigEncoderCodesPerRev(100);

	m_rf = new CANTalon(DRIVE_RF_PORT);
	m_rf->SetControlMode(frc::CANSpeedController::kFollower);
	m_rf->Set(m_rb->GetDeviceID());

	m_log->Log(this, Logger::kInfo, "Left Master: " + std::to_string(m_lb->GetDeviceID()) +
			" Right Master: " + std::to_string(m_rb->GetDeviceID()));

	SetTalonMode(CANTalon::kThrottleMode);
	set_pid_values();

	m_log->Log(this, Logger::kInfo,
			"Left Master P: " + std::to_string(m_lb->GetP()) +
			" I: " + std::to_string(m_lb->GetI()) +
			" D: " + std::to_string(m_lb->GetD()));
	m_log->Log(this, Logger::kInfo,
			"Right Master P: " + std::to_string(m_rb->GetP()) +
			" I: " + std::to_string(m_rb->GetI()) +
			" D: " + std::to_string(m_rb->GetD()));

	//m_rf->SetInverted(true);
	//m_rb->SetInverted(true);
	m_lb->SetInverted(true);

	m_rb->SetSensorDirection(false);
	m_lb->SetSensorDirection(false); // For encoder inversion

	m_shiftState = m_shifter->Get();

	frc::LiveWindow::GetInstance()->AddActuator("Drive", "Drive Left", m_lb);
	frc::LiveWindow::GetInstance()->AddActuator("Drive", "Drive Left S", m_lf);
	frc::LiveWindow::GetInstance()->AddActuator("Drive", "Drive Right", m_rb);
	frc::LiveWindow::GetInstance()->AddActuator("Drive", "Drive Right S", m_rf);
}

void DriveTrain::DashboardOutput(bool verbose)
{
	frc::SmartDashboard::PutString("Drive Gear", m_shifter->Get() == HIGH ? "High" : "Low");

	if (verbose)
	{
		frc::SmartDashboard::PutNumber("Count L", m_lb->GetEncVel());
		frc::SmartDashboard::PutNumber("Count R", m_rb->GetEncVel());

		frc::SmartDashboard::PutNumber("Left Out", m_lb->Get());
		frc::SmartDashboard::PutNumber("Right Out", m_rb->Get());
	}
}

CANTalon::TalonControlMode DriveTrain::GetTalonMode()
{
	return (CANTalon::TalonControlMode)(m_lb->GetTalonControlMode() & m_rb->GetTalonControlMode());
}

void DriveTrain::set_pid_values()
{
	for (int i = 0; i < 2; i++)
	{
		m_lb->SelectProfileSlot(i);
		m_rb->SelectProfileSlot(i);
		m_lb->SetPID(
				DRIVE_LEFT_P,
				DRIVE_LEFT_I,
				DRIVE_LEFT_D);
		m_lb->SetF(DRIVE_LEFT_F);
		m_rb->SetPID(
				DRIVE_RIGHT_P,
				DRIVE_RIGHT_I,
				DRIVE_RIGHT_D);
		m_rb->SetF(DRIVE_RIGHT_F);
	}
}

void DriveTrain::SetTalonMode(CANTalon::TalonControlMode mode)
{
	m_lb->SetTalonControlMode(mode);
	m_rb->SetTalonControlMode(mode);

	if (mode == CANTalon::kSpeedMode)
	{
		m_lb->Set(0);
		m_rb->Set(0);
	}

	//set_pid_values();
}

void DriveTrain::ArcadeDrive(double move, double rotate)
{
	// Maybe log
	if (m_disabled) return;
	if (m_reverse)
	{
		move = -move;
		rotate = -rotate;
	}

	double leftMotorOutput;
	double rightMotorOutput;

	if (move > 0.0)
	{
		if (rotate > 0.0)
		{
			leftMotorOutput = move - rotate;
			rightMotorOutput = std::max(move, rotate);
		}
		else
		{
			leftMotorOutput = std::max(move, -rotate);
			rightMotorOutput = move + rotate;
		}
	}
	else
	{
		if (rotate > 0.0)
		{
			leftMotorOutput = -std::max(-move, rotate);
		  	rightMotorOutput = move + rotate;
		}
		else
		{
			leftMotorOutput = move - rotate;
			rightMotorOutput = -std::max(-move, -rotate);
		}
	}

	m_lb->Set(leftMotorOutput);
	m_rb->Set(-rightMotorOutput);
}

void DriveTrain::TankDrive(double left, double right)
{
	// Maybe log
	if (m_disabled) return;
	if (m_reverse)
	{
		left = -left;
		right = -right;
	}
	m_lb->Set(left);
	m_rb->Set(-right);
}

void DriveTrain::Reverse()
{
	m_reverse = !m_reverse;
	m_lb->SetInverted(m_reverse);
}

void DriveTrain::Shift()
{
	if (m_disabled) return;
	m_shifter->Set(m_shifter->Get() == HIGH ? LOW : HIGH);
	//m_scaleFactor = m_shiftState ? 0.5 : 1.0;
	m_log->Log(this, Logger::kInfo, "Shifted to: " + (m_shifter->Get() == HIGH) ? "high" : "low");
}

void DriveTrain::SetScale(double scale)
{
	m_scaleFactor = scale;
}

double DriveTrain::GetScale()
{
	return m_scaleFactor;
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

void DriveTrain::ResetEnc()
{
	m_lb->SetEncPosition(0);
	m_rb->SetEncPosition(0);
}

void DriveTrain::Coast()
{
	Disable();
	m_lb->ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
	m_rb->ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
	m_lb->Set(0);
	m_rb->Set(0);
}

void DriveTrain::StopCoast()
{
	m_lb->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
	m_rb->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
	Enable();
}
