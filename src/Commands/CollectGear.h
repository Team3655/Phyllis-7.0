#ifndef CollectGear_H
#define CollectGear_H

#include "../CommandBase.h"

class CollectGear : public CommandBase {
public:
	CollectGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CollectGear_H
