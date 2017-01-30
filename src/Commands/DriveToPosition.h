#ifndef DRIVE_TO_POSITION_H
#define DRIVE_TO_POSITION_H

#include "../CommandBase.h"

class DriveToPosition : public CommandBase
{
public:
	DriveToPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DRIVE_TO_POSITION_H
