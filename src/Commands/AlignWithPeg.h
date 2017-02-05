#ifndef ALIGN_WITH_PEG_H
#define ALIGN_WITH_PEG_H

#include "../CommandBase.h"

class AlignWithPeg : public CommandBase
{
public:
	AlignWithPeg();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ALIGN_WITH_PEG_H
