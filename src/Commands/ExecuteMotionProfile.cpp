#include "ExecuteMotionProfile.h"

ExecuteMotionProfile::ExecuteMotionProfile(double profiles[][3], int size)
{
	Requires(drive.get());

	m_profiles = profiles;
	m_size = size;

	m_motionControl = new MotionControl(drive.get());
}

ExecuteMotionProfile::~ExecuteMotionProfile()
{
}

void ExecuteMotionProfile::Initialize()
{
	m_motionControl->Fill(0, m_size, m_profiles, m_size);
}

void ExecuteMotionProfile::Execute()
{
	m_motionControl->Run();
}

bool ExecuteMotionProfile::IsFinished()
{
	return false;
}

void ExecuteMotionProfile::End()
{

}

void ExecuteMotionProfile::Interrupted()
{

}
