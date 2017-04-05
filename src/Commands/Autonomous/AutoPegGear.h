#ifndef AUTO_PEG_GEAR_H
#define AUTO_PEG_GEAR_H

#include "../../RobotMap.h"

#include <Commands/CommandGroup.h>
#include <vector>

// Summary:
// Pegs a gear
class AutoPegGear : public frc::CommandGroup
{
public:
	AutoPegGear(
		double delay,
		const std::vector<Profile>& prePeg,
		const std::vector<Profile>& retry,
		const std::vector<Profile>& postPeg);
};

#endif // AUTO_PEG_GEAR_H
