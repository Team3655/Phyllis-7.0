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
	for (const Profile& p : prePeg)
	{
		AddSequential(new MagicDrive(p));
		AddSequential(new Delay(2));
	}
	AddSequential(new DelayForGear());
	for (const Profile& p : retry)
		AddSequential(new MagicDrive(p));
	for (const Profile& p : postPeg)
		AddSequential(new MagicDrive(p));
}
