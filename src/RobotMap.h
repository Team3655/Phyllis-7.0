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

//---------------------------------------------------------
// Drive
constexpr int DRIVE_LF_PORT = 9;
constexpr int DRIVE_LEFT_PORT = 5;
constexpr int DRIVE_RF_PORT = 8;
constexpr int DRIVE_RIGHT_PORT = 6;

constexpr int DRIVE_SHIFT_PORT = 0;

// Left
constexpr double DRIVE_LEFT_POS_P = .1;
constexpr double DRIVE_LEFT_POS_I = .003;
constexpr double DRIVE_LEFT_POS_D = 2;
constexpr double DRIVE_LEFT_SPD_P = .1;
constexpr double DRIVE_LEFT_SPD_I = .003;
constexpr double DRIVE_LEFT_SPD_D = 2;
// Right
constexpr double DRIVE_RIGHT_POS_P = 2;
constexpr double DRIVE_RIGHT_POS_I = .01;
constexpr double DRIVE_RIGHT_POS_D = .1;
constexpr double DRIVE_RIGHT_SPD_P = 2;
constexpr double DRIVE_RIGHT_SPD_I = .01;
constexpr double DRIVE_RIGHT_SPD_D = .1;

constexpr double DRIVE_ALLOWED_ERROR = 100;

constexpr double DRIVE_DEFAULT_SCALE = 1.0;

constexpr int DRIVE_ENC_CPR = 1440;

//---------------------------------------------------------
// Shooter
constexpr int SHOOT_MOTOR_PORT = 6;

//---------------------------------------------------------
// Gear Collector
constexpr int GEAR_INTAKE_PORT = 0;
constexpr int GEAR_TRANS_PORT = 1;
constexpr double GEAR_MOTOR_SPEED = .5;

//---------------------------------------------------------
// Climber
constexpr int CLIMB_LEFT_PORT = 0;
constexpr int CLIMB_RIGHT_PORT = 1;
constexpr double CLIMB_UP_POS = 0;

//---------------------------------------------------------
// Fuel Collector
constexpr int FUEL_GATE_PORT = 0;
constexpr int FUEL_INTAKE_PORT = 0;
constexpr double FUEL_INTAKE_SPEED = 0;
constexpr double FUEL_INTAKE_P = 1;
constexpr double FUEL_INTAKE_I = 0;
constexpr double FUEL_INTAKE_D = 0;

//---------------------------------------------------------
// Input
//#define CODRIVER  	// Use def check when referencing the co-driver stick
constexpr int JOY_DRIVER_PORT = 0;
constexpr int JOY_CODRIVER_PORT = 1;

//---------------------------------------------------------
// Camera
constexpr int CS_PEG_CAM_PORT = 0;
constexpr int CS_SHOOT_CAM_PORT = 1;

//---------------------------------------------------------
// Utility functions
inline bool is_about(double target, double acceptableRange)
{
	return target >= target + acceptableRange && target < target - acceptableRange;
}

#endif  // ROBOTMAP_H
