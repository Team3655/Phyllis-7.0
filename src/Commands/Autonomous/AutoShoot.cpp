#include "AutoShoot.h"
#include "../Shoot.h"

AutoShoot::AutoShoot()
{
	AddSequential(new Shoot(SHOOT_SPEED, true));
}
