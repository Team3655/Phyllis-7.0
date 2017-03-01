#include "AutoPegGear.h"

#include "../DriveProfile.h"
#include "../WaitForPeg.h"

AutoPegGear::AutoPegGear(std::list<Profile*>* prePegSeq, std::list<Profile*>* postPegSeq)
{
	if (prePegSeq != nullptr)
		AddSequential(new DriveProfile(*prePegSeq));
	AddSequential(new WaitForPeg());
	if (postPegSeq != nullptr)
		AddSequential(new DriveProfile(*postPegSeq));
}
