#include "Shift.h"
#include "../Logger.h"

Shift::Shift() :
	CommandBase("Shift")
{
	Requires(CommandBase::drive.get());
}

void Shift::Initialize()
{
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "Shift");
	CommandBase::drive.get()->Shift();
	Logger::GetInstance()->Log("cmds", Logger::kExit, "Shift");
}
