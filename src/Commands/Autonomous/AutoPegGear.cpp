#include "AutoPegGear.h"

#include "../DriveProfile.h"
#include "../AlignWithPeg.h"
#include "../WaitForPeg.h"
#include "../Delay.h"
#include "../EjectGear.h"

AutoPegGear::AutoPegGear(double delay, std::list<Profile*>* prePegSeq, std::list<Profile*>* pegPr, std::list<Profile*>* postPegSeq)
{
	AddSequential(new Delay(delay));
	if (prePegSeq != nullptr)
		AddSequential(new DriveProfile(*prePegSeq));
	//AddSequential(new AlignWithPeg(nullptr));
	if (pegPr != nullptr)
		AddSequential(new DriveProfile(*pegPr));
	AddSequential(new EjectGear());
	AddSequential(new WaitForPeg());
	if (postPegSeq != nullptr)
		AddSequential(new DriveProfile(*postPegSeq));
	AddSequential(new EjectGear());
}
