#include "WaitForPeg.h"

WaitForPeg::WaitForPeg()
{
	Requires(drive.get());
	Requires(gearCollector.get());
}

void WaitForPeg::Initialize()
{
	drive.get()->Disable();
}

void WaitForPeg::Execute()
{
	// Maybe flash lights
}

bool WaitForPeg::IsFinished()
{
	return !gearCollector.get()->IsGearPresent();
}

void WaitForPeg::End()
{
	drive.get()->Enable();
}

void WaitForPeg::Interrupted()
{
}
