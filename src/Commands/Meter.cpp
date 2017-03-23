#include "Meter.h"

Meter::Meter()
{
	Requires(CommandBase::fuelCollector.get());
}

void Meter::Initialize()
{
	CommandBase::fuelCollector.get()->Index(!CommandBase::fuelCollector.get()->GetIndex());
}
