#include "AutoCrossLine.h"

#include "../Delay.h"
#include "../DriveProfile.h"

AutoCrossLine::AutoCrossLine(double delay)
{
	AddSequential(new Delay(delay));
	std::list<Profile*> seq;
	AddSequential(new DriveProfile(seq));
}
