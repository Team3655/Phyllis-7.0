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

//#define TEMP

//---------------------------------------------------------
// Drive
constexpr int DRIVE_LF_PORT = 1;
constexpr int DRIVE_LEFT_PORT = 3;
constexpr int DRIVE_RF_PORT = 2;
constexpr int DRIVE_RIGHT_PORT = 4;

constexpr int DRIVE_SHIFT_PORT = 0;

// Left
constexpr double DRIVE_LEFT_POS_P = .1;
constexpr double DRIVE_LEFT_POS_I = .003;
constexpr double DRIVE_LEFT_POS_D = 2;
constexpr double DRIVE_LEFT_SPD_P = 1;
constexpr double DRIVE_LEFT_SPD_I = 0;
constexpr double DRIVE_LEFT_SPD_D = 0;
// Right
constexpr double DRIVE_RIGHT_POS_P = 2;
constexpr double DRIVE_RIGHT_POS_I = .01;
constexpr double DRIVE_RIGHT_POS_D = .1;
constexpr double DRIVE_RIGHT_SPD_P = 1;
constexpr double DRIVE_RIGHT_SPD_I = 0;
constexpr double DRIVE_RIGHT_SPD_D = 0;

constexpr double DRIVE_ALLOWED_ERROR = 100;

constexpr double DRIVE_DEFAULT_SCALE = 1.0;

constexpr int DRIVE_ENC_CPR = 1440;

//---------------------------------------------------------
// Shooter
constexpr int SHOOT_MOTOR_PORT = 7;
constexpr double SHOOT_P = 1;
constexpr double SHOOT_I = 0;
constexpr double SHOOT_D = 0;
constexpr double SHOOT_SPEED = .5; // Temp
constexpr double SHOOT_RESET_TIME = 500; // ms
constexpr double SHOOT_MAX_CPMS = 1.0; // unknown

//---------------------------------------------------------
// Gear Collector
constexpr int GEAR_INTAKE_PORT = 5;
constexpr double GEAR_INTAKE_SPEED = 0.4;
constexpr int GEAR_TRANS_PORT = 6;
constexpr double GEAR_TRANS_SPEED = -0.5;

//---------------------------------------------------------
// Climber
constexpr int CLIMB_LEFT_PORT = 0;
constexpr double CLIMB_LEFT_P = 1;
constexpr double CLIMB_LEFT_I = 0;
constexpr double CLIMB_LEFT_D = 0;
constexpr int CLIMB_RIGHT_PORT = 1;
constexpr double CLIMB_RIGHT_P = 1;
constexpr double CLIMB_RIGHT_I = 0;
constexpr double CLIMB_RIGHT_D = 0;
constexpr double CLIMB_UP_POS = 0;

//---------------------------------------------------------
// Fuel Collector
constexpr int FUEL_METER_PORT = 0; // unknown
constexpr int FUEL_METER_P = 1.0;
constexpr int FUEL_METER_I = 0.0;
constexpr int FUEL_METER_D = 0.0;
constexpr double FUEL_METER_CPR = 1024; // unknown
constexpr double FUEL_BALL_PER_TURN = 4; // unknown
constexpr int FUEL_INTAKE_PORT = 8;
constexpr double FUEL_INTAKE_SPEED = 0;
constexpr double FUEL_INTAKE_P = 1;
constexpr double FUEL_INTAKE_I = 0;
constexpr double FUEL_INTAKE_D = 0;

//---------------------------------------------------------
// Input
//#define CODRIVER  	// Use def check when referencing the co-driver stick
constexpr int JOY_DRIVER_PORT = 0;
constexpr int JOY_CODRIVER_PORT = 1;
constexpr int JOY_BOARD_PORT = 2;
constexpr int JOY_BOARD_PORT2 = 3;

//---------------------------------------------------------
// Camera
constexpr int CS_CAM_PEG_PORT = 0;
constexpr int CS_CAM_SHOOT_PORT = 1;
constexpr int CS_CAM_RES_X = 480;
constexpr int CS_CAM_RES_Y = 360;
constexpr double CS_CAM_HORIZON_ANGLE = 0.0; // unknown

//--------------------------------------------------------
// Lights
constexpr int LIGHT_RED_PORT = 1;
constexpr int LIGHT_GREEN_PORT = 2;
constexpr int LIGHT_BLUE_PORT = 3;

//---------------------------------------------------------
// Utility functions
inline bool is_about(double target, double value, double acceptableRange)
{
	return target >= target + acceptableRange && target < target - acceptableRange;
}

#endif  // ROBOTMAP_H
