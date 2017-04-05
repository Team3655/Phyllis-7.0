#ifndef AUTO_PEG_AND_SHOOT_H
#define AUTO_PEG_AND_SHOOT_H

#include "../../RobotMap.h"

#include <Commands/CommandGroup.h>
#include <vector>

class AutoPegAndShoot : public frc::CommandGroup
{
public:
	AutoPegAndShoot(
		double delay,
		const std::vector<Profile>& prePeg,
		const std::vector<Profile>& retry,
		const std::vector<Profile>& postPeg);
};

#endif // AUTO_PEG_AND_SHOOT_H
