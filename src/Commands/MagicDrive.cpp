#include "MagicDrive.h"

MagicDrive::MagicDrive(const Profile& pr)
{
	Requires(drive.get());

	m_profile = pr;
	m_drive = drive;
	m_driveLeft = m_drive->m_lb;
	m_driveRight = m_drive->m_rb;
}

void MagicDrive::Initialize()
{
	if (m_profile.isEmpty) return;
	m_previousMode = m_drive->GetTalonMode();
	m_drive->SetTalonMode(CANTalon::kMotionMagicMode);
	m_driveLeft->ConfigNeutralMode(frc::CANSpeedController::NeutralMode::kNeutralMode_Brake);
	m_driveRight->ConfigNeutralMode(frc::CANSpeedController::NeutralMode::kNeutralMode_Brake);
	m_driveLeft->SetMotionMagicCruiseVelocity(m_profile.cruise);
	m_driveRight->SetMotionMagicCruiseVelocity(m_profile.cruise);
	m_driveLeft->SetMotionMagicAcceleration(m_profile.ramp);
	m_driveRight->SetMotionMagicAcceleration(m_profile.ramp);
	m_drive->ResetEnc();
}

void MagicDrive::Execute()
{
	if (m_profile.isEmpty) return;
	m_driveLeft->Set(m_profile.leftDist);
	m_driveRight->Set(m_profile.rightDist);

	std::cout << m_driveLeft->GetEncVel() << "  " << m_driveRight->GetEncVel() << std::endl;
}

bool MagicDrive::IsFinished()
{
	return m_profile.isEmpty || is_finished();
}

void MagicDrive::End()
{
	m_drive->ResetEnc();
	m_drive->SetTalonMode(m_previousMode);
	std::cout << "Finished" << std::endl;
}

void MagicDrive::Interrupted()
{
}

bool MagicDrive::is_finished()
{
	if (m_driveLeft->GetEncVel() == 0 && m_driveRight->GetEncVel() == 0 && !m_triggered)
	{
		m_timer.Start();
		m_triggered = true;
	}
	else if (m_driveLeft->GetEncVel() != 0 || m_driveRight->GetEncVel() != 0)
	{
		m_timer.Stop();
		m_timer.Reset();
		m_triggered = false;
	}
	return m_timer.HasPeriodPassed(1);
}
