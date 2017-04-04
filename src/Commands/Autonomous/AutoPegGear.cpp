#include "AutoPegGear.h"

#include "../MagicDrive.h"
#include "../DelayForGear.h"
#include "../Delay.h"

AutoPegGear::AutoPegGear(double delay, std::vector<Profile>& prePeg, std::vector<Profile>& retry, std::vector<Profile>& postPeg)
{
	AddSequential(new Delay(delay));
	for (auto itr = prePeg.begin(); itr != prePeg.end(); itr++)
		AddSequential(new MagicDrive(*itr));
	AddSequential(new DelayForGear());
	AddSequential(new MagicDrive(retry));
	for (auto itr = postPeg.begin(); itr != postPeg.end(); itr++)
		AddSequential(new MagicDrive(*itr));
}
