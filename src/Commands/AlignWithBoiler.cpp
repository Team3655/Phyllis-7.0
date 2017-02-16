#include "AlignWithBoiler.h"

AlignWithBoiler::AlignWithBoiler(frc::JoystickButton* abortBtn)
{
	Requires(drive.get());
	Requires(visionManager.get());

	frc::Preferences* prefs = oi.get()->GetPrefs();

	m_pid = new frc::PIDController(
			prefs->GetDouble("align_drive_p"),
			prefs->GetDouble("align_drive_i"),
			prefs->GetDouble("align_drive_d"),
			drive.get(),
			visionManager.get());

	m_abortBtn = abortBtn;
}

AlignWithBoiler::~AlignWithBoiler()
{
	delete m_pid;
}

void AlignWithBoiler::Initialize()
{
	m_pid->SetTolerance(ALIGN_BOILER_TOLERANCE);
	visionManager.get()->SwitchCamera(CS_CAM_SHOOT_PORT);
	drive.get()->SetTalonMode(CANTalon::TalonControlMode::kPositionMode);
}

void AlignWithBoiler::Execute()
{
	m_pid->SetSetpoint(0);
}

bool AlignWithBoiler::IsFinished()
{
	return m_pid->OnTarget();
}

void AlignWithBoiler::End()
{

}

void AlignWithBoiler::Interrupted()
{

}
