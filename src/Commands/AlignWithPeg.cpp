#include "AlignWithPeg.h"
#include "../AlignPIDWrapper.h"

#include <Preferences.h>

#include "../Logger.h"

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
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "AlignWithPeg");
	Logger::GetInstance()->Log("cmds", Logger::kInfo, "AlignWithPeg P: " + std::to_string(m_pid->GetP()) +
			" I: " + std::to_string(m_pid->GetI()) +
			" D: " + std::to_string(m_pid->GetD()));

	//m_pid->SetTolerance(ALIGN_PEG_TOLERANCE);
	drive.get()->SetTalonMode(CANTalon::kThrottleMode);
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
	Logger::GetInstance()->Log("cmds", Logger::kExit, "AlignWithPeg");
}

void AlignWithPeg::Interrupted()
{
	Logger::GetInstance()->Log("cmds", Logger::kInfo, "AlignWithPeg interrupted");
}
