///////////////////////////////////////////////////////////////////////////////
//
// AlignPIDWrapper.cpp
//
//  Created on: Feb 16, 2017
//     Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include "AlignPIDWrapper.h"
#include "CommandBase.h"

#include <SmartDashboard/SmartDashboard.h>

AlignPIDWrapper::AlignPIDWrapper()
{
	// Uses DriveTrain
}

double AlignPIDWrapper::PIDGet()
{
	return frc::SmartDashboard::GetNumber("CenterX", -2);
}

void AlignPIDWrapper::PIDWrite(double output)
{
	CommandBase::drive.get()->ArcadeDrive(ALIGN_FORWARD_SPEED, output);
}
