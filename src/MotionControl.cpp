///////////////////////////////////////////////////////////////////////////////
//
// MotionControl.cpp
//
//  Created on: Feb 18, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include "MotionControl.h"

MotionControl::MotionControl(DriveTrain* drive) :
	m_notifier(new frc::Notifier(&MotionControl::periodic_tasks, this)),
	m_driveLeft(drive->m_lb), m_driveRight(drive->m_rb)
{
	drive->SetTalonMode(CANTalon::TalonControlMode::kMotionProfileMode);

	m_driveLeft->ChangeMotionControlFramePeriod(5);
	m_driveRight->ChangeMotionControlFramePeriod(5);

	m_notifier->StartPeriodic(.01); // 10ms
}

MotionControl::~MotionControl()
{
	m_notifier->Stop();
	delete m_notifier;
}

void MotionControl::periodic_tasks()
{
	m_driveLeft->ProcessMotionProfileBuffer();
	m_driveRight->ProcessMotionProfileBuffer();
}

Point MotionControl::create_point(double position, double velocity, double duration, int slot, bool first, bool last, bool velOnly)
{
	Point point;
	point.position = position;
	point.velocity = velocity;
	point.timeDurMs = duration;
	point.profileSlotSelect = slot;
	point.zeroPos = first;
	point.isLastPoint = last;
	point.velocityOnly = velOnly;
	return point;
}

void MotionControl::Fill()
{

}

void MotionControl::Fill(int start, int end, double profile[][3], int profileSize)
{
	m_driveLeft->ClearMotionProfileTrajectories();
	m_driveRight->ClearMotionProfileTrajectories();

	for (int i = start; i < end; i++)
	{
		Point pt = create_point(profile[i][0], profile[i][1], profile[i][2], 1, i == 0, i + 1 == profileSize);
		m_driveLeft->PushMotionProfileTrajectory(pt);
		m_driveRight->PushMotionProfileTrajectory(pt);
	}
}

void MotionControl::Run()
{
}
