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
	for (auto itr = prePeg.begin(); itr != prePeg.end(); itr++)
		AddSequential(new MagicDrive(*itr));
	AddSequential(new DelayForGear());
	for (auto itr = retry.begin(); itr != retry.end(); itr++)
		AddSequential(new MagicDrive(*itr));
	for (auto itr = postPeg.begin(); itr != postPeg.end(); itr++)
		AddSequential(new MagicDrive(*itr));
}
