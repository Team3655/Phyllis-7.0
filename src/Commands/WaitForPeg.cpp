#include "WaitForPeg.h"
#include "../Logger.h"

WaitForPeg::WaitForPeg()
{
	Requires(drive.get());
	Requires(gearCollector.get());

	m_lightFlashTimer = new frc::Timer();
	m_gearGoneTimer = new frc::Timer();
}

WaitForPeg::~WaitForPeg()
{
	delete m_abortBtn;
	delete m_lightFlashTimer;
	delete m_gearGoneTimer;
}

void WaitForPeg::Initialize()
{
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "WaitForPeg");

	drive.get()->Disable();
	m_lightFlashTimer->Start();

	std::string code = oi.get()->GetPrefs()->GetString("joy_btn_peg_abort");
	m_abortBtn = new frc::JoystickButton(oi.get()->GetStick(oi.get()->InterpretStick(code)), oi.get()->InterpretButton(code));

	Logger::GetInstance()->Log("cmds", Logger::kInfo, "WaitForPeg Abort Button initialized to " + code);
}

void WaitForPeg::Execute()
{
	if (m_lightFlashTimer->HasPeriodPassed(GEAR_SENSOR_FLASH_INTERVAL / 1000))
		m_toggle = !m_toggle;
	if (m_toggle)
	{
		m_lightFlashTimer->Reset();
		lights.get()->SetColor(RED);
	}
	else
	{
		m_lightFlashTimer->Reset();
		lights.get()->SetColor(OFF);
	}

	if (!gearCollector.get()->IsGearPresent())
		m_gearGoneTimer->Start();
}

bool WaitForPeg::IsFinished()
{
	return (!gearCollector.get()->IsGearPresent() && m_gearGoneTimer->HasPeriodPassed(GEAR_SENSOR_ELAPSED_TIME / 1000))
			|| m_abortBtn->Get();
}

void WaitForPeg::End()
{
	Logger::GetInstance()->Log("cmds", Logger::kExit, "WaitForPeg");
	drive.get()->Enable();
}

void WaitForPeg::Interrupted()
{
	Logger::GetInstance()->Log("cmds", Logger::kInfo, "WaitForPeg interrupted");
}
