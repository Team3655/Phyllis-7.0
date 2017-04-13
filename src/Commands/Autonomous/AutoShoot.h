#ifndef AUTO_SHOOT_H
#define AUTO_SHOOT_H

#include <Commands/CommandGroup.h>
#include "RobotMap.h"

// Summary:
// Shoot fuel in auto
class AutoShoot : public frc::CommandGroup
{
public:
	AutoShoot(const std::vector<Profile>& postShoot);
};

#endif // AUTO_SHOOT_H
