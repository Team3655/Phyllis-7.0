///////////////////////////////////////////////////////////////////////////////
//
// RobotMap.h
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef ROBOTMAP_H
#define ROBOTMAP_H

// Drive
constexpr int DRIVE_LEFT_PORT = 1;
constexpr int DRIVE_RIGHT_PORT = 2;

// Shooter
constexpr int SHOOT_MOTOR_PORT = 6;

// Gear Collector
constexpr int GEAR_INTAKE_PORT = 0;
constexpr int GEAR_TRANS_PORT = 1;

// Climber
constexpr int CLIMB_LEFT_PORT = 0;
constexpr int CLIMB_RIGHT_PORT = 1;

// Input
//#define CODRIVER  	// Use def check when referencing the co-driver stick
constexpr int JOY_DRIVER_PORT = 0;
constexpr int JOY_CODRIVER_PORT = 1;

// Camera
constexpr int CS_PORT = 0;

#endif  // ROBOTMAP_H
