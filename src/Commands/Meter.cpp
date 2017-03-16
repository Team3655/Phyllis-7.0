#include "Meter.h"

Meter::Meter()
{
	Requires(CommandBase::fuelCollector.get());
}

void Meter::Initialize()
{
	static double last = 0;
	CommandBase::fuelCollector.get()->Index(last);
	last = last == 0 ? 90 : 0;
}
