/*
 * ExtSubsystem.h
 *
 *  Created on: Jan 21, 2017
 *      Author: Silas A.
 */

#ifndef EXT_SUBSYSTEM_H
#define EXT_SUBSYSTEM_H

// Summary:
// 	Abstract class to implement an initializer to prevent segmentation faults
//  for static construction of subsystems
class ExtSubsystem
{
public:
	virtual ~ExtSubsystem() {}

	// Implement to initialize wpilib classes
	virtual	void Initialize() = 0;
};

#endif // EXT_SUBSYSTEM_H
