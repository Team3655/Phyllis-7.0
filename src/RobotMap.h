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

#include <thread>

//---------------------------------------------------------
// Drive
constexpr int DRIVE_LF_PORT = 0;
constexpr int DRIVE_LEFT_PORT = 1;
constexpr int DRIVE_RF_PORT = 15;
constexpr int DRIVE_RIGHT_PORT = 14;

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
constexpr int SHOOT_MOTOR_PORT = 6;
constexpr double SHOOT_P = 1;
constexpr double SHOOT_I = 0;
constexpr double SHOOT_D = 0;
constexpr double SHOOT_SPEED = .5; // Temp
constexpr double SHOOT_RESET_TIME = 500; // ms
constexpr double SHOOT_MAX_CPMS = 1.0; // unknown

//---------------------------------------------------------
// Gear Collector
constexpr int GEAR_INTAKE_PORT = 4;
constexpr double GEAR_INTAKE_SPEED = 0.4;
constexpr int GEAR_TRANS_BACK_PORT = 11;
//constexpr int GEAR_TRANS_FRONT_PORT = 0; // unknown
constexpr double GEAR_TRANS_SPEED = -0.5;

//---------------------------------------------------------
// Climber
constexpr int CLIMB_LEFT_PORT = 2;
constexpr int CLIMB_RIGHT_PORT = 13;

//---------------------------------------------------------
// Fuel Collector
constexpr int FUEL_METER_PORT = 10; // unknown
constexpr int FUEL_METER_P = 1.0;
constexpr int FUEL_METER_I = 0.0;
constexpr int FUEL_METER_D = 0.0;
constexpr double FUEL_METER_CPR = 1024; // unknown
constexpr double FUEL_BALL_PER_TURN = 4; // unknown
constexpr int FUEL_INTAKE_PORT = 5;
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
constexpr int CS_CAM_FPS_DEFAULT = 20;
constexpr double CS_CAM1_HORIZON_ANGLE = 0.0; // unknown
constexpr double CS_CAM2_HORIZON_ANGLE = 0.0; // unknown
constexpr double CS_TARGET_BOILER_HEIGHT = 5.51467;
constexpr double CS_TARGET_PEG_HEIGHT = 0.0;

//-------------------------------------------------------=
// Alignment
constexpr double ALIGN_DRIVE_P = 1.0;
constexpr double ALIGN_DRIVE_I = 0.0;
constexpr double ALIGN_DRIVE_D = 0.0;
constexpr double ALIGN_FORWARD_SPEED = .4;
constexpr double ALIGN_ACCEPT_DIST_CLOSE = 1.0; // unknown
constexpr double ALIGN_PEG_TOLERANCE = .1;
constexpr double ALIGN_BOILER_TOLERANCE = .05;
constexpr double ALIGN_DIST_P = 1.0;
constexpr double ALIGN_DIST_I = 0.0;
constexpr double ALIGN_DIST_D = 0.0;

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

inline void sleep(uint timeMS)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(timeMS));
}

#endif  // ROBOTMAP_H
