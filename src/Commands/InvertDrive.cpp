#include "InvertDrive.h"
#include "../Logger.h"

InvertDrive::InvertDrive()
{
	Requires(CommandBase::drive.get());
}

void InvertDrive::Initialize()
{
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "InvertDrive");
	CommandBase::drive.get()->Reverse();
	Logger::GetInstance()->Log("cmds", Logger::kExit, "InvertDrive");
}
