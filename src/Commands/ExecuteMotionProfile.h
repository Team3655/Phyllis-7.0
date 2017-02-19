#ifndef EXECUTE_MOTION_PROFILE_H
#define EXECUTE_MOTION_PROFILE_H

#include "../CommandBase.h"
#include "../MotionControl.h"

// Summary:
//
class ExecuteMotionProfile : public CommandBase
{
private:
	MotionControl* m_motionControl;

	double m_profiles[][3];
	int m_size;

public:
	ExecuteMotionProfile(double profiles[][3], int size);
	~ExecuteMotionProfile();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // EXECUTE_MOTION_PROFILE_H
