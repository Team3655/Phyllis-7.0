#ifndef DriveToPosition_H
#define DriveToPosition_H

#include "../CommandBase.h"

class DriveToPosition : public CommandBase {
public:
	DriveToPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveToPosition_H
