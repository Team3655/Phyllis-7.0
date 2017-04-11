#include "AutoShoot.h"
#include "../Shoot.h"
#include "../MagicDrive.h"

AutoShoot::AutoShoot(const std::vector<Profile>& postShoot)
{
	AddSequential(new Shoot(SHOOT_SPEED, true));
	for (const Profile& p : postShoot)
		AddSequential(new MagicDrive(p));
}
