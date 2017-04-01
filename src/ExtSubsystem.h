/*
 * ExtSubsystem.h
 *
 *  Created on: Jan 21, 2017
 *      Author: Silas A.
 */

#ifndef EXT_SUBSYSTEM_H
#define EXT_SUBSYSTEM_H

#include <Preferences.h>
#include <Timer.h>

// Summary:
// 	Abstract class to implement an initializer to prevent segmentation faults
//  for static construction of subsystems
class ExtSubsystem
{
protected:
	frc::Timer* m_timer;

public:
	ExtSubsystem() :
		m_timer(new frc::Timer()) {}

	virtual ~ExtSubsystem() {}

	// Implement to initialize wpilib classes
	virtual	void Initialize(frc::Preferences* prefs) = 0;

	virtual void DashboardOutput(bool verbose) {}
};

#endif // EXT_SUBSYSTEM_H
