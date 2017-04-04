#ifndef AUTO_PEG_GEAR_H
#define AUTO_PEG_GEAR_H

#include <Commands/CommandGroup.h>
#include <vector>

// Summary:
//
class AutoPegGear : public frc::CommandGroup
{
public:
	AutoPegGear(
		double delay,
		std::vector<Profile>& prePeg,
		std::vector<Profile>& retry,
		std::vector<Profile>& postPeg);
};

#endif // AUTO_PEG_GEAR_H
