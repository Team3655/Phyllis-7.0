#include "AutoCrossLine.h"

#include "../Delay.h"
#include "../DriveProfile.h"
#include "../../Logger.h"

AutoCrossLine::AutoCrossLine(double delay, std::list<Profile*>* seq)
{
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "AutoCrossLine");

	AddSequential(new Delay(delay));
	AddSequential(new DriveProfile(*seq));
}
