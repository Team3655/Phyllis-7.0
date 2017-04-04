#ifndef AUTO_PEG_AND_SHOOT_H
#define AUTO_PEG_AND_SHOOT_H

#include <Commands/CommandGroup.h>
#include <vector>

class AutoPegAndShoot : public frc::CommandGroup
{
public:
	AutoPegAndShoot(std::vector<Profile>& prePeg, std::vector<Profile>& postPeg);
};

#endif // AUTO_PEG_AND_SHOOT_H
