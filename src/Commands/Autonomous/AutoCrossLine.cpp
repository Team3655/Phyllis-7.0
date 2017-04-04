#include "AutoCrossLine.h"

#include "../Delay.h"
#include "../MagicDrive.h"
#include "../../Logger.h"

AutoCrossLine::AutoCrossLine(double delay)
{
	AddSequential(new Delay(delay));
	AddSequential(new MagicDrive(make_profile_inches(81.5)));
}
