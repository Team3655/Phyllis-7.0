#ifndef DRIVE_PROFILE_H
#define DRIVE_PROFILE_H

#include "../CommandBase.h"
#include "../MotionControl.h"

// Summary:
//
class DriveProfile : public CommandBase
{
private:
	MotionControl* m_motionControl;

	int m_start, m_end, m_prSize;
	double m_profile[][3];

public:
	DriveProfile(int start, int end, int prSize, double profile[]);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // DRIVE_PROFILE_H
