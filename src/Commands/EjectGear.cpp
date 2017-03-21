#include "EjectGear.h"

EjectGear::EjectGear()
{
	Requires(CommandBase::gearCollector.get());
}

void EjectGear::Initialize()
{
	CommandBase::gearCollector.get()->Eject(CommandBase::gearCollector.get()->IsEjected());
}
