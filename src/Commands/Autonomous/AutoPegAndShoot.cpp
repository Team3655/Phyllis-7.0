#include "AutoPegAndShoot.h"

#include "../Delay.h"
#include "../MagicDrive.h"
#include "../WaitForPeg.h"

AutoPegAndShoot::AutoPegAndShoot(std::vector<Profile>& prePeg, std::vector<Profile>& postPeg)
{
	for (auto itr = prePeg.begin(); itr != prePeg.end(); itr++)
		AddSequential(new MagicDrive(*itr));
	AddSequential(new WaitForPeg());
	for (auto itr = postPeg.begin(); itr != postPeg.end(); itr++)
		AddSequential(new MagicDrive(*itr));
}
