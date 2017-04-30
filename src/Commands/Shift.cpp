#include "Shift.h"
#include "../Logger.h"

Shift::Shift()
{
	Requires(CommandBase::drive.get());
}

void Shift::Initialize()
{
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "Shift");
	if (CommandBase::oi->IsDemoMode()) return;
	CommandBase::drive.get()->Shift();
	Logger::GetInstance()->Log("cmds", Logger::kExit, "Shift");
}
