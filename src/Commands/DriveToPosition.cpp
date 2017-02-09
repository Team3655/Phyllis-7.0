#include "DriveToPosition.h"

DriveToPosition::DriveToPosition(double position)
{
	Requires(drive.get());

	m_position = position;
}

void DriveToPosition::Initialize()
{
	//drive.get()->SetTalonMode(CANTalon::TalonControlMode::kPositionMode);
}

void DriveToPosition::Execute()
{
	drive.get()->SetPosition(m_position);
	drive.get()->GetPosition(m_lPosition, m_rPosition);
}

bool DriveToPosition::IsFinished()
{
	return is_about(m_position, m_lPosition, 50.0) &&
		   is_about(m_position, m_rPosition, 50.0) &&
		   drive.get()->GetVelocity() == 0.0;
}

void DriveToPosition::End()
{
}

void DriveToPosition::Interrupted()
{
}
