#include "Shift.h"
#include "../Logger.h"

Shift::Shift()
{
	Requires(CommandBase::drive.get());
}

void Shift::Initialize()
{
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "Shift");
}

void Shift::Execute()
{
	CommandBase::drive.get()->Shift();
}

bool Shift::IsFinished()
{
	return true;
}

void Shift::End()
{
	Logger::GetInstance()->Log("cmds", Logger::kExit, "Shift");
}

void Shift::Interrupted()
{
	Logger::GetInstance()->Log("cmds", Logger::kInfo, "Shift interrupted");
}
