#include "MagicDrive.h"

MagicDrive::MagicDrive(Profile& pr)
{
	Requires(drive.get());

	m_profile = pr;
	m_drive = drive;
	m_driveLeft = m_drive->m_lb;
	m_driveRight = m_drive->m_rb;
}

void MagicDrive::Initialize()
{
	m_previousMode = m_drive->GetTalonMode();
	m_drive->SetTalonMode(CANTalon::kMotionMagicMode);
	m_driveLeft->ConfigNeutralMode(frc::CANSpeedController::NeutralMode::kNeutralMode_Brake);
	m_driveRight->ConfigNeutralMode(frc::CANSpeedController::NeutralMode::kNeutralMode_Brake);
	m_driveLeft->SetMotionMagicCruiseVelocity(m_profile.cruise);
	m_driveRight->SetMotionMagicCruiseVelocity(m_profile.cruise);
	m_driveLeft->SetMotionMagicAcceleration(m_profile.ramp);
	m_driveRight->SetMotionMagicAcceleration(m_profile.ramp);
}

void MagicDrive::Execute()
{
	m_driveLeft->Set(m_profile.leftDist);
	m_driveRight->Set(m_profile.rightDist);
}

bool MagicDrive::IsFinished()
{
	return false; // TODO: find when done
}

void MagicDrive::End()
{
	m_drive->ResetEnc();
	m_drive->SetTalonMode(m_previousMode);
}

void MagicDrive::Interrupted()
{
}
