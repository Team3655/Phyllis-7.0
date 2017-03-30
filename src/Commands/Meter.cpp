#include "Meter.h"
#include "../Logger.h"

Meter::Meter()
{
	Requires(CommandBase::fuelCollector.get());
}

void Meter::Initialize()
{
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "Meter");
	CommandBase::fuelCollector.get()->Index(!CommandBase::fuelCollector.get()->GetIndex());
	Logger::GetInstance()->Log("cmds", Logger::kExit, "Meter");
}
