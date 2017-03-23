#include "AlignWithPeg.h"
#include "../AlignPIDWrapper.h"

#include <Preferences.h>

AlignWithPeg::AlignWithPeg(frc::JoystickButton* abortBtn)
{
	Requires(drive.get());
	Requires(visionManager.get());
	Requires(lights.get());

	frc::Preferences* prefs = oi.get()->GetPrefs();

	AlignPIDWrapper* pidSO = new AlignPIDWrapper();

	m_pid = new frc::PIDController(
			prefs->GetDouble("align_drive_p"),
			prefs->GetDouble("align_drive_i"),
			prefs->GetDouble("align_drive_d"),
			pidSO,
			pidSO);

	m_abortBtn = abortBtn;

	lights.get()->SetPegCamLight(true);
}

AlignWithPeg::~AlignWithPeg()
{
	delete m_pid;
}

void AlignWithPeg::Initialize()
{
	//m_pid->SetTolerance(ALIGN_PEG_TOLERANCE);
	drive.get()->SetTalonMode(CANSpeedController::kPercentVbus);
}

void AlignWithPeg::Execute()
{
	m_pid->SetSetpoint(0);
}

bool AlignWithPeg::IsFinished()
{
	return m_pid->OnTarget() || (m_abortBtn != nullptr) ? m_abortBtn->Get() : false;
}

void AlignWithPeg::End()
{
	lights.get()->SetPegCamLight(false);
}

void AlignWithPeg::Interrupted()
{
}
