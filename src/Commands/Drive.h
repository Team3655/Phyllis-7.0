#ifndef Drive_H
#define Drive_H

#include "../CommandBase.h"

class Drive : public CommandBase {
public:
	Drive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Drive_H
