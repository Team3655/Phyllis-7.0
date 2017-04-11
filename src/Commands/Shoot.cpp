#include "Shoot.h"
#include "../Logger.h"

Shoot::Shoot(double speedProp, bool auton)
{
	Requires(shooter.get());
	Requires(fuelCollector.get());
	Requires(drive.get());

	m_auton = auton;
	m_speedProportion = speedProp * SHOOT_MAX_SPEED;
}

void Shoot::Initialize()
{
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "Shoot");

	std::string code = oi.get()->GetPrefs()->GetString("joy_btn_shoot_end");
	m_abortBtn = new frc::JoystickButton(oi.get()->GetStick(2), 9);

	Logger::GetInstance()->Log("cmds", Logger::kInfo, "Shoot Abort Button initialized to " + code);

	if (m_auton) m_timer.Start();
}

void Shoot::Execute()
{
	shooter.get()->Set(m_speedProportion);
}

bool Shoot::IsFinished()
{
	if (m_auton)
		return m_timer.HasPeriodPassed(SHOOT_AUTO_TIME);
	else
		return m_abortBtn->Get();
}

void Shoot::End()
{
	Logger::GetInstance()->Log("cmds", Logger::kExit, "Shoot");
	shooter.get()->Set(0);
	fuelCollector.get()->Index(false);

	m_timer.Stop();
	m_timer.Reset();
}

void Shoot::Interrupted()
{
	Logger::GetInstance()->Log("cmds", Logger::kInfo, "Shoot interrupted");
}
