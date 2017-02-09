#ifndef DRIVE_TO_POSITION_H
#define DRIVE_TO_POSITION_H

#include "../CommandBase.h"

class DriveToPosition : public CommandBase
{
private:
	double m_position;
	double m_lPosition,
		   m_rPosition;

public:
	DriveToPosition(double position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DRIVE_TO_POSITION_H
