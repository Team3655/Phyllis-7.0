///////////////////////////////////////////////////////////////////////////////
//
// MotionControl.cpp
//
//  Created on: Feb 18, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include "MotionControl.h"

void MotionControl::periodic_tasks()
{
	m_driveLeft->ProcessMotionProfileBuffer();
	m_driveRight->ProcessMotionProfileBuffer();
}

MotionControl::MotionControl(DriveTrain* drive, std::list<Profile*>& sequence) :
	m_notifier(new frc::Notifier(&MotionControl::periodic_tasks, this)),
	m_driveLeft(drive->m_lb), m_driveRight(drive->m_rb),
	m_sequence(sequence)
{
	drive->SetTalonMode(CANTalon::TalonControlMode::kMotionProfileMode);

	m_driveLeft->ChangeMotionControlFramePeriod(5);
	m_driveRight->ChangeMotionControlFramePeriod(5);

	m_notifier->StartPeriodic(.01); // 10ms
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

Point MotionControl::invert_point(Point& point)
{
	point.position = -point.position;
	point.velocity = -point.velocity;
	return point;
}

void MotionControl::Fill(int start, int end, Profile& profile)
{
	m_driveLeft->ClearMotionProfileTrajectories();
	m_driveRight->ClearMotionProfileTrajectories();

	Point pt;

	for (int i = start; i < end; i++)
	{
		pt = create_point(profile.profile[i][0], profile.profile[i][1], profile.profile[i][2], 1, i == 0, i + 1 == profile.size);
		m_driveLeft->PushMotionProfileTrajectory(profile.turn == RIGHT ? invert_point(pt) : pt);
		m_driveRight->PushMotionProfileTrajectory(profile.turn == LEFT ? invert_point(pt) : pt);
	}
}

void MotionControl::Update()
{
	m_driveLeft->GetMotionProfileStatus(m_leftStatus);
	m_driveRight->GetMotionProfileStatus(m_rightStatus);

	if (m_loopTimeout < 0); // nothing
	else
	{
		if (m_loopTimeout == 0)
			;// error
		else
			--m_loopTimeout;
	}

	if (m_driveLeft->GetTalonControlMode() != CANTalon::kMotionProfileMode ||
		m_driveRight->GetTalonControlMode() != CANTalon::kMotionProfileMode)
	{
		// Not in MP mode
	}
	else
	{
		bool l = false, r = false;
		bool ls = false, rs = false;
		switch (m_state)
		{
		case 0:
			m_leftSetValue = CANTalon::SetValueMotionProfileDisable;
			m_rightSetValue = CANTalon::SetValueMotionProfileDisable;

			Fill(0, (*m_currentPr)->size - 1, *(*m_currentPr));

			m_state = 1;
			m_loopTimeout = TIMEOUT_LOOPS;
			break;
		case 1:

			if (m_leftStatus.btmBufferCnt > MIN_POINTS)
			{
				m_leftSetValue = CANTalon::SetValueMotionProfileEnable;
				ls = true;
			}
			if (m_rightStatus.btmBufferCnt > MIN_POINTS)
			{
				m_rightSetValue = CANTalon::SetValueMotionProfileEnable;
				rs = true;
			}

			if (rs && ls)
			{
				m_state = 2;
				m_loopTimeout = TIMEOUT_LOOPS;
			}
			break;
		case 2:
			if (!m_leftStatus.isUnderrun || !m_rightStatus.isUnderrun)
				m_loopTimeout = TIMEOUT_LOOPS;

			if (m_leftStatus.activePointValid && m_leftStatus.activePoint.isLastPoint)
			{
				m_leftSetValue = CANTalon::SetValueMotionProfileHold;
				l = true;
			}
			if (m_rightStatus.activePointValid && m_rightStatus.activePoint.isLastPoint)
			{
				m_rightSetValue = CANTalon::SetValueMotionProfileHold;
				r = true;
			}

			if (l && r)
			{
				m_state = 0;
				m_loopTimeout = -1;

				m_currentPr++;
				if (m_currentPr == m_sequence.end())
					m_state = -1;
			}
			break;
		}
	}
}
