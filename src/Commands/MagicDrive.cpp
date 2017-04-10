#include "MagicDrive.h"

int MagicDrive::m_previousLeftRot = 0;
int MagicDrive::m_previousRightRot = 0;

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
	//m_drive->ResetEnc();
}

void MagicDrive::Execute()
{
	if (m_profile.isEmpty) return;
	m_driveLeft->Set(m_previousLeftRot + m_profile.leftDist);
	m_driveRight->Set(m_previousRightRot + m_profile.rightDist);
}

bool MagicDrive::IsFinished()
{
	return m_profile.isEmpty || is_finished();
}

void MagicDrive::End()
{
	m_previousLeftRot += m_profile.leftDist;
	m_previousRightRot += m_profile.rightDist;
	m_drive->SetTalonMode(m_previousMode);
	std::cout << "Finished" << std::endl;
}

void MagicDrive::Interrupted()
{
}

bool MagicDrive::is_finished()
{
	bool lt = is_about(m_profile.leftDist, (double)m_driveLeft->GetEncPosition() / 400, .5);
	bool rt = is_about(m_profile.rightDist, (double)m_driveRight->GetEncPosition() / 400, .5);

	std::cout << m_driveLeft->GetSetpoint() << " " << m_driveRight->GetSetpoint() << std::endl;
	std::cout << m_driveLeft->Get() << "  " << m_driveRight->Get() << std::endl;

	if (lt && rt &&
		m_driveLeft->GetEncVel() == 0 && m_driveRight->GetEncVel() == 0 &&
		!m_triggered)
	{
		m_timer.Start();
		m_triggered = true;
	}
	else if (!lt && !rt &&
			m_driveLeft->GetEncVel() != 0 && m_driveRight->GetEncVel() != 0)
	{
		m_timer.Stop();
		m_timer.Reset();
		m_triggered = false;
	}
	return m_timer.HasPeriodPassed(MAGIC_FINISH_WAIT_TIME);
}
