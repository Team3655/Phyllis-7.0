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
constexpr int DRIVE_LF_PORT = 1;
constexpr int DRIVE_LB_PORT = 2;
constexpr int DRIVE_RF_PORT = 3;
constexpr int DRIVE_RB_PORT = 4;

constexpr int DRIVE_LEFT_SHIFT_PORT = 0;
constexpr int DRIVE_RIGHT_SHIFT_PORT = 1;

constexpr double DRIVE_LF_P = 1;
constexpr double DRIVE_LF_I = 0;
constexpr double DRIVE_LF_D = 0;
constexpr double DRIVE_LB_P = 1;
constexpr double DRIVE_LB_I = 0;
constexpr double DRIVE_LB_D = 0;
constexpr double DRIVE_RF_P = 1;
constexpr double DRIVE_RF_I = 0;
constexpr double DRIVE_RF_D = 0;
constexpr double DRIVE_RB_P = 1;
constexpr double DRIVE_RB_I = 0;
constexpr double DRIVE_RB_D = 0;

constexpr int DRIVE_ENC_CPR = 4096;

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
