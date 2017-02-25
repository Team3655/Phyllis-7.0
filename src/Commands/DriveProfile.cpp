#include "DriveProfile.h"

DriveProfile::DriveProfile(int start, int end, int prSize, double profile[]) :
	m_start(start), m_end(end), m_prSize(prSize), m_profile(profile)
{
	Requires(drive.get());

	m_motionControl = new MotionControl(drive.get());
}

void DriveProfile::Initialize()
{
	m_motionControl->Fill(m_start, m_end, m_profile, m_prSize);
}

void DriveProfile::Execute()
{
	m_motionControl->
}

bool DriveProfile::IsFinished()
{
	return false;
}

void DriveProfile::End()
{

}

void DriveProfile::Interrupted()
{

}
