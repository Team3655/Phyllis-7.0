#ifndef COLLECT_GEAR_H
#define COLLECT_GEAR_H

#include "../CommandBase.h"

class CollectGear : public CommandBase
{
public:
	CollectGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // COLLECT_GEAR_H
