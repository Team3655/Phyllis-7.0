#include "CollectGear.h"
#include "../Logger.h"

CollectGear::CollectGear(bool direction)
{
	Requires(gearCollector.get());

	m_direction = direction;
}

void CollectGear::Initialize()
{
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "CollectGear");

	std::string code = oi.get()->GetPrefs()->GetString("joy_btn_gear_end_collect");
	m_endBtn = new frc::JoystickButton(oi.get()->GetStick(2), 9);

	Logger::GetInstance()->Log("cmds", Logger::kInfo, "CollectGear end button initialized to 2-9");
}

void CollectGear::Execute()
{
	gearCollector.get()->SetIntake(m_direction ? FORWARD : BACKWARD);
}

bool CollectGear::IsFinished()
{
	return m_endBtn->Get();
}

void CollectGear::End()
{
	gearCollector.get()->Stop();
	Logger::GetInstance()->Log("cmds", Logger::kExit, "CollectGear");
}

void CollectGear::Interrupted()
{
	Logger::GetInstance()->Log("cmds", Logger::kExit, "CollectGear interrupted");
}
