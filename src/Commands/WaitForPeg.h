#ifndef WAIT_FOR_PEG_H
#define WAIT_FOR_PEG_H

#include "../CommandBase.h"

class WaitForPeg : public CommandBase
{
public:
	WaitForPeg();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // WAIT_FOR_PEG_H
