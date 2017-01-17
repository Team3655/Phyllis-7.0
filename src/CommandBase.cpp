///////////////////////////////////////////////////////////////////////////////
//
// CommandBase.cpp
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include "CommandBase.h"

#include <Commands/Scheduler.h>


std::unique_ptr<DriveTrain> CommandBase::drive =
		std::make_unique<DriveTrain>();
std::unique_ptr<Shooter> CommandBase::shooter =
		std::make_unique<Shooter>();
std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();

// Add Subsystems

CommandBase::CommandBase(const std::string& name) :
		frc::Command(name)
{

}
