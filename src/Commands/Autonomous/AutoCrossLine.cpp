#include "AutoCrossLine.h"

#include "../Delay.h"
#include "../MagicDrive.h"
#include "../Shift.h"
#include "../../Logger.h"
#include "../../RobotMap.h"

AutoCrossLine::AutoCrossLine(double delay)
{
	AddSequential(new Delay(delay));
	AddSequential(new MagicDrive(make_profile_inches(MAGIC_BASELINE_CROSS)));
}
