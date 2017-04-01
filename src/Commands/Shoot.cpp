#include "Shoot.h"
#include "../Logger.h"

Shoot::Shoot(double speedProp)
{
	Requires(shooter.get());
	Requires(fuelCollector.get());
	Requires(drive.get());

	m_isAligned = false;
	m_speedProportion = speedProp * 13000;
}

void Shoot::Initialize()
{
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "Shoot");

	std::string code = oi.get()->GetPrefs()->GetString("joy_btn_shoot_end");
	m_abortBtn = new frc::JoystickButton(oi.get()->GetStick(2), 9);

	Logger::GetInstance()->Log("cmds", Logger::kInfo, "Shoot Abort Button initialized to " + code);

	//drive.get()->Disable();
	m_isAligned = false; // Get alignment
}

void Shoot::Execute()
{
	shooter.get()->Set(m_speedProportion);
}

bool Shoot::IsFinished()
{
	// When no more balls are present or not aligned or abort pressed
	return m_abortBtn->Get(); //!isAligned
}

void Shoot::End()
{
	Logger::GetInstance()->Log("cmds", Logger::kExit, "Shoot");
	shooter.get()->Set(0);
	fuelCollector.get()->Index(false);
	//drive.get()->Enable();
}

void Shoot::Interrupted()
{
	Logger::GetInstance()->Log("cmds", Logger::kInfo, "Shoot interrupted");
}
