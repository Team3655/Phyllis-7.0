#ifndef AlignWithBoiler_H
#define AlignWithBoiler_H

#include "../CommandBase.h"

class AlignWithBoiler : public CommandBase {
public:
	AlignWithBoiler();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AlignWithBoiler_H
