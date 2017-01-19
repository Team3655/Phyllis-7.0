#ifndef AlignWithPeg_H
#define AlignWithPeg_H

#include "../CommandBase.h"

class AlignWithPeg : public CommandBase {
public:
	AlignWithPeg();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AlignWithPeg_H
