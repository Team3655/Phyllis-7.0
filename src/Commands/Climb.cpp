#include "Climb.h"
#include "../Logger.h"

Climb::Climb(frc::JoystickButton* thisBtn, double speed)
{
	Requires(climber.get());

	m_thisBtn = thisBtn;
	m_speed = speed;
}

Climb::~Climb()
{
}

void Climb::Initialize()
{
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "Climb");
	Logger::GetInstance()->Log("cmds", Logger::kInfo, "Climb speed: " + std::to_string(m_speed));
}

void Climb::Execute()
{
	climber.get()->SetSpeed(-m_speed);
}

bool Climb::IsFinished()
{
	return !m_thisBtn->Get();
}

void Climb::End()
{
	climber.get()->SetSpeed(0);
	Logger::GetInstance()->Log("cmds", Logger::kExit, "Climb");
}

void Climb::Interrupted()
{
	Logger::GetInstance()->Log("cmds", Logger::kInfo, "Climb interrupted");
}
