#include "AutoPegGear.h"

#include "../DriveProfile.h"
#include "../AlignWithPeg.h"
#include "../DelayForGear.h"
#include "../Delay.h"
#include "../EjectGear.h"

AutoPegGear::AutoPegGear(double delay, std::list<Profile*>* prePegSeq, std::list<Profile*>* pegPr, std::list<Profile*>* postPegSeq)
{
	//Logger::GetInstance()->Log("cmds", Logger::kEnter, "AutoPegGear");

	AddSequential(new Delay(delay));
	if (prePegSeq != nullptr)
		AddSequential(new DriveProfile(*prePegSeq));
	//AddSequential(new AlignWithPeg(nullptr));
	if (pegPr != nullptr)
		AddSequential(new DriveProfile(*pegPr));
	AddSequential(new EjectGear());
	AddSequential(new DelayForGear());

	std::list<Profile*> seq;
	seq.push_back(new Profile(NOT_REVERSE, Mp28p5Size, Mp28p5, false));
	seq.push_back(new Profile(REVERSE, Mp28p5Size, Mp28p5, false));
	AddSequential(new DriveProfile(seq));

	//if (postPegSeq != nullptr)
	//	AddSequential(new DriveProfile(*postPegSeq));
	AddSequential(new EjectGear());
}
