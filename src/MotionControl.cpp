///////////////////////////////////////////////////////////////////////////////
//
// MotionControl.cpp
//
//  Created on: Feb 18, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include "MotionControl.h"

#include <iostream>

void MotionControl::periodic_tasks()
{
	m_driveLeft->ProcessMotionProfileBuffer();
	m_driveRight->ProcessMotionProfileBuffer();
}

MotionControl::MotionControl(std::shared_ptr<DriveTrain> drive, std::list<Profile*>& sequence) :
	m_notifier(new frc::Notifier(&MotionControl::periodic_tasks, this)),
	m_driveLeft(drive->m_lb), m_driveRight(drive->m_rb), m_drive(drive),
	m_sequence(sequence), m_log(Logger::GetInstance())
{
	m_log->AddLog("mp");
	m_log->Log("mp", Logger::kEnter);
	m_log->StreamLog("mp");

	m_timer = new frc::Timer();
}

MotionControl::~MotionControl()
{
	delete m_notifier;
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

void MotionControl::fill()
{
	m_log->Log("mp", Logger::kInfo, "Filling started");
	std::list<Profile*>::iterator pr = m_sequence.begin();
	int count = 0;
	while (pr != m_sequence.end())
	{
		bool finished = false;
		int idx = 0;
		CANTalon::MotionProfileStatus left, right;
		Point pt;

		Profile* profile = *pr;
		m_log->Log("mp", Logger::kInfo, "Filling profile " + std::to_string(count + 1));

		while (!finished)
		{
			m_driveLeft->GetMotionProfileStatus(left);
			m_driveRight->GetMotionProfileStatus(right);
			if (left.topBufferCnt >= 127 || right.topBufferCnt >= 127)
			{
				m_log->Log("mp", Logger::kWarning, "Top buffer full on count " + std::to_string(idx));
				sleep(50);
				continue;
			}
			pt = create_point(profile->profile[idx][0], profile->profile[idx][1], profile->profile[idx][2], 1, idx == 0, idx == profile->size - 1);
			if (profile->turn == LEFT)
			{
				m_driveLeft->PushMotionProfileTrajectory(invert_point(pt));
				m_driveRight->PushMotionProfileTrajectory(pt);
			}
			else if (profile->turn == RIGHT)
			{
				m_driveLeft->PushMotionProfileTrajectory(pt);
				m_driveRight->PushMotionProfileTrajectory(pt);
			}
			else if (profile->turn == NOT_REVERSE)
			{
				m_driveLeft->PushMotionProfileTrajectory(pt);
				m_driveRight->PushMotionProfileTrajectory(invert_point(pt));
			}
			else if (profile->turn == REVERSE)
			{
				m_driveLeft->PushMotionProfileTrajectory(invert_point(pt));
				m_driveRight->PushMotionProfileTrajectory(invert_point(pt));
			}
			idx++;
			if (idx >= profile->size)
				finished = true;
			m_log->Log("mp", Logger::kInfo, "Profile Count: " + idx);
		}
		pr++;
	}
}

void MotionControl::Fill()
{
	if (m_beenFilled) return;

	if (m_leftStatus.hasUnderrun)
		m_driveLeft->ClearMotionProfileHasUnderrun();
	if (m_rightStatus.hasUnderrun)
		m_driveRight->ClearMotionProfileHasUnderrun();

	//if (m_fillerThread != nullptr) delete m_fillerThread;
	m_fillerThread = new std::thread(&MotionControl::fill, this);
	m_beenFilled = true;
}

void MotionControl::Initialize()
{
	m_currentPr = m_sequence.begin();
	if (m_currentPr != m_sequence.end()) m_state = 0;

	m_drive->SetTalonMode(frc::CANSpeedController::kMotionProfile);

	m_driveLeft->ChangeMotionControlFramePeriod(5);
	m_driveRight->ChangeMotionControlFramePeriod(5);

	m_notifier->StartPeriodic(.005); // 5ms

	m_drive->Disable();

	m_driveRight->Enable();

	m_timer->Start();
}

void MotionControl::Update()
{
	m_driveLeft->GetMotionProfileStatus(m_leftStatus);
	m_driveRight->GetMotionProfileStatus(m_rightStatus);

	if (m_loopTimeout < 0); // nothing
	else
	{
		if (m_loopTimeout == 0)
			if (m_timer->HasPeriodPassed(LOG_RESOLUTION))
				m_log->Log("mp", Logger::kWarning, "Profiles in timeout");
		else
			--m_loopTimeout;
	}

	if (m_driveLeft->GetControlMode() != frc::CANSpeedController::kMotionProfile ||
		m_driveRight->GetControlMode() != frc::CANSpeedController::kMotionProfile)
	{
		return;
	}
	switch (m_state)
	{
	case -1:
		m_isFinished = true;
		m_log->Log("mp", Logger::kInfo, "Motion Profiles finished");
		break;
	case 0:
		m_leftSetValue = CANTalon::SetValueMotionProfileDisable;
		m_rightSetValue = CANTalon::SetValueMotionProfileDisable;

		m_log->Log("mp", Logger::kInfo, "Starting new profile");

		m_driveLeft->SetEncPosition(0);
		m_driveRight->SetEncPosition(0);

		Fill();

		m_state = 1;
		m_loopTimeout = TIMEOUT_LOOPS;

		break;
	case 1:
		if (m_leftStatus.btmBufferCnt > MIN_POINTS && m_rightStatus.btmBufferCnt > MIN_POINTS)
		{
			m_state = 2;
			m_loopTimeout = TIMEOUT_LOOPS;
			m_rightSetValue = CANTalon::SetValueMotionProfileEnable;
			m_leftSetValue = CANTalon::SetValueMotionProfileEnable;
		}
		break;
	case 2:
		if (!m_leftStatus.isUnderrun || !m_rightStatus.isUnderrun)
		{
			m_loopTimeout = TIMEOUT_LOOPS;
			if (m_timer->HasPeriodPassed(LOG_RESOLUTION))
				m_log->Log("mp", Logger::kWarning, "Motion Profiles Underrun");
		}

		if ((m_leftStatus.activePointValid && m_leftStatus.activePoint.isLastPoint) &&
			(m_rightStatus.activePointValid && m_rightStatus.activePoint.isLastPoint))
		{
			m_state = 0;
			m_loopTimeout = -1;

			m_leftSetValue = CANTalon::SetValueMotionProfileHold;
			m_rightSetValue = CANTalon::SetValueMotionProfileHold;

			m_currentPr++;
			if (m_currentPr == m_sequence.end())
				m_state = -1;
		}
		break;
	}
	m_driveLeft->Set(m_leftSetValue);
	m_driveRight->Set(m_rightSetValue);

	if (m_timer->HasPeriodPassed(LOG_RESOLUTION))
		m_log->Log("mp", Logger::kInfo, "Mp State: " + std::to_string(m_state));

	if (m_timer->HasPeriodPassed(LOG_RESOLUTION))
		m_timer->Reset();
}

void MotionControl::Finish()
{
	m_drive->Enable();
	m_drive->SetTalonMode(frc::CANSpeedController::kPercentVbus);
	m_log->StopStreamLog();
	m_log->Log("mp", Logger::kExit);
}
