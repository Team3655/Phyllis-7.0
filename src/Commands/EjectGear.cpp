#include "EjectGear.h"
#include "../Logger.h"

EjectGear::EjectGear()
{
	Requires(CommandBase::gearCollector.get());
}

void EjectGear::Initialize()
{
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "EjectGear");
	CommandBase::gearCollector.get()->Eject(!CommandBase::gearCollector.get()->IsEjected());
	Logger::GetInstance()->Log("cmds", Logger::kExit, "EjectGear");
}
