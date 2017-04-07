#include "AutoPegAndShoot.h"

#include "AutoPegGear.h"
#include "../Delay.h"
#include "../MagicDrive.h"
#include "../WaitForPeg.h"
#include "../Shoot.h"

AutoPegAndShoot::AutoPegAndShoot(
		double delay,
        const std::vector<Profile>& prePeg,
        const std::vector<Profile>& retry,
        const std::vector<Profile>& postPeg)
{
	/*AddSequential(new Delay(0));
	for (auto itr = prePeg.begin(); itr != prePeg.end(); itr++)
		AddSequential(new MagicDrive(*itr));
	AddSequential(new WaitForPeg());
	for (auto itr = retry.begin(); itr != retry.end(); itr++)
			AddSequential(new MagicDrive(*itr));
	for (auto itr = postPeg.begin(); itr != postPeg.end(); itr++)
		AddSequential(new MagicDrive(*itr));*/
	AddSequential(new Shift(LOW));
	AddSequential(new Shoot(SHOOT_SPEED));
	AddSequential(new AutoPegGear(delay, prePeg, retry, postPeg));
}
