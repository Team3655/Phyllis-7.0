///////////////////////////////////////////////////////////////////////////////
//
// MotionControl.h
//
//  Created on: Feb 18, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef MOTION_CONTROL_H
#define MOTION_CONTROL_H

#include "Subsystems/DriveTrain.h"
#include "RobotMap.h"

#include <Notifier.h>
#include <CANTalon.h>

typedef CANTalon::TrajectoryPoint Point;

// Summary:
//
class MotionControl
{
private:
	CANTalon::MotionProfileStatus m_status;

	CANTalon* m_driveLeft;
	CANTalon* m_driveRight;

	frc::Notifier* m_notifier;

	void periodic_tasks();
	Point create_point(double position, double velocity, double duration, int slot, bool first, bool last, bool velOnly = false);

public:
	MotionControl(DriveTrain* drive);

	void Fill();
	void Fill(int start, int end, double profile[][3], int profileSize);
};

#endif // MOTION_CONTROL_H
