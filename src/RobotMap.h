///////////////////////////////////////////////////////////////////////////////
//
// RobotMap.h
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef ROBOT_MAP_H
#define ROBOT_MAP_H

#include <thread>

//---------------------------------------------------------
// Drive
constexpr int DRIVE_LF_PORT = 0;
constexpr int DRIVE_LEFT_PORT = 1;
constexpr int DRIVE_RF_PORT = 15;
constexpr int DRIVE_RIGHT_PORT = 14;

constexpr int DRIVE_SHIFT_HIGH_PORT = 0;
constexpr int DRIVE_SHIFT_LOW_PORT = 1;

// Left
constexpr double DRIVE_LEFT_P = 1.0; // 1.03
constexpr double DRIVE_LEFT_I = 0.0; // .0103
constexpr double DRIVE_LEFT_D = 0.0; // 10.3
constexpr double DRIVE_LEFT_F = 1.49343; // 1.49343
// Right
constexpr double DRIVE_RIGHT_P = 1.0; // 2.0
constexpr double DRIVE_RIGHT_I = 0.0; // .02
constexpr double DRIVE_RIGHT_D = 0.0; // 20.0
constexpr double DRIVE_RIGHT_F = 1.566616; // 1.566616

constexpr double DRIVE_ALLOWED_ERROR = 10;

constexpr double DRIVE_MAX_SPEED = 1068;

//---------------------------------------------------------
// Shooter
constexpr int SHOOT_MOTOR_PORT = 6;
constexpr double SHOOT_P = 0.05;
constexpr double SHOOT_I = 0;
constexpr double SHOOT_D = 0.5;
constexpr double SHOOT_F = 0.00937181;
constexpr double SHOOT_SPEED = .5;
constexpr double SHOOT_RESET_TIME = 500; // ms
//constexpr double SHOOT_MAX_SPEED = 93972; // counts/100ms

//---------------------------------------------------------
// Gear Collector
constexpr int GEAR_INTAKE_PORT = 4;
constexpr int GEAR_SENSOR_PORT = 9;
constexpr double GEAR_SENSOR_ELAPSED_TIME = 2000; // ms
constexpr double GEAR_SENSOR_FLASH_INTERVAL = 1000; // ms
constexpr double GEAR_INTAKE_SPEED = -0.4; // Maybe faster
constexpr int GEAR_TRANS_BACK_PORT = 11;
constexpr int GEAR_TRANS_FRONT_PORT = 12;
constexpr double GEAR_TRANS_SPEED = 0.5;
constexpr int GEAR_EJECTOR_F_PORT = 2;
constexpr int GEAR_EJECTOR_B_PORT = 3;

//---------------------------------------------------------
// Climber
constexpr int CLIMB_LEFT_PORT = 2;
constexpr int CLIMB_RIGHT_PORT = 13;
constexpr double CLIMB_SPEED = .6;

//---------------------------------------------------------
// Fuel Collector
constexpr int FUEL_METER_F_PORT = 4;
constexpr int FUEL_METER_B_PORT = 5;
constexpr int FUEL_INTAKE_PORT = 5;
constexpr double FUEL_INTAKE_SPEED = -.9;

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
constexpr int CS_CAM_RES_X = 360;
constexpr int CS_CAM_RES_Y = 240;
constexpr int CS_CAM_FPS_DEFAULT = 20;
constexpr double CS_CAM_FOV = 68.5;
constexpr double CS_CAM1_HORIZON_ANGLE = 0.0; // unknown
constexpr double CS_CAM2_HORIZON_ANGLE = 0.0; // unknown
constexpr double CS_TARGET_BOILER_HEIGHT = 5.51467;
constexpr double CS_TARGET_PEG_HEIGHT = 0.0;

//--------------------------------------------------------
// Image Processing
constexpr double IMG_RESIZE_W = 360.0;
constexpr double IMG_RESIZE_H = 240.0;
constexpr double IMG_HSV_HI_HUE[] = { 40, 80 };
//constexpr double IMG_HSV_LO_HUE[] = { 155, 180 }; // Runs hi first
constexpr double IMG_HSL_SAT[] = { 100, 255 };
constexpr double IMG_HSL_LUM[] = { 50, 255 };
constexpr double IMG_CONT_MIN_AREA = 10;
constexpr double IMG_CONT_MIN_PERIM = 10;
constexpr double IMG_CONT_MIN_WIDTH = 10;
constexpr double IMG_CONT_MAX_WIDTH = 1000;
constexpr double IMG_CONT_MIN_HEIGHT = 5;
constexpr double IMG_CONT_MAX_HEIGHT = 100;
constexpr double IMG_CONT_SOLID[] = { 50, 100.0 };
constexpr double IMG_CONT_MAX_VERTEX = 1000000;
constexpr double IMG_CONT_MIN_VERTEX = 0.0;
constexpr double IMG_CONT_MIN_RATIO = 0;
constexpr double IMG_CONT_MAX_RATIO = 1000;

//--------------------------------------------------------
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
constexpr int LIGHT_PEG_PORT = 6;
constexpr int LIGHT_RED_PORT = 3;
constexpr int LIGHT_GREEN_PORT = 5;
constexpr int LIGHT_BLUE_PORT = 6;

//---------------------------------------------------------
// Utility Functions

// If a number is within a range rather than equal to
inline bool is_about(double target, double value, double acceptableRange)
{
	return target >= target + acceptableRange && target < target - acceptableRange;
}

// Wrapper for this_thread::sleep_for()
inline void sleep(uint timeMS)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(timeMS));
}

constexpr double LOG_RESOLUTION = 1;

//----------------------------------------------------------
// Motion Profiling

constexpr int MIN_POINTS = 5;
constexpr int TIMEOUT_LOOPS = 10;

// Profiles in Profiles.h

#endif // ROBOT_MAP_H
