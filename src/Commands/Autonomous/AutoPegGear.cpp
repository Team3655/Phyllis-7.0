#include "AutoPegGear.h"

#include "../MagicDrive.h"
#include "../DelayForGear.h"
#include "../Delay.h"

AutoPegGear::AutoPegGear(
		double delay,
		const std::vector<Profile>& prePeg,
		const std::vector<Profile>& retry,
		const std::vector<Profile>& postPeg)
{
	AddSequential(new Delay(delay));
	for (Profile& p : prePeg)
		AddSequential(new MagicDrive(p));
	AddSequential(new DelayForGear());
	for (Profile& p : retry)
		AddSequential(new MagicDrive(p));
	for (Profile& p : postPeg)
		AddSequential(new MagicDrive(p));
}
