#include "AutoPegGear.h"

#include "../DriveProfile.h"
#include "../WaitForPeg.h"

AutoPegGear::AutoPegGear(std::list<Profile*>& prePegSeq, std::list<Profile*>& postPegSeq)
{
	AddSequential(new DriveProfile(prePegSeq));
	AddSequential(new WaitForPeg());
	AddSequential(new DriveProfile(postPegSeq));
}
