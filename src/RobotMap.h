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
#include <cmath>

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
constexpr double DRIVE_LEFT_F = 3.41; // 1.49343
// Right
constexpr double DRIVE_RIGHT_P = 1.0; // 2.0
constexpr double DRIVE_RIGHT_I = 0.0; // .02
constexpr double DRIVE_RIGHT_D = 0.0; // 20.0
constexpr double DRIVE_RIGHT_F = 3.41; // 1.566616

constexpr double DRIVE_ALLOWED_ERROR = 10;

constexpr double DRIVE_MAX_SPEED = 1068;

//---------------------------------------------------------
// Shooter
constexpr int SHOOT_MOTOR_PORT = 6;
constexpr double SHOOT_P = 0.05;
constexpr double SHOOT_I = 0;
constexpr double SHOOT_D = 0.5;
constexpr double SHOOT_F = 0.00937181;
constexpr double SHOOT_SPEED = .48;
constexpr double SHOOT_AUTO_TIME = 10;
constexpr double SHOOT_MAX_SPEED = 13000;

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
constexpr double CLIMB_SPEED_FAST = .95;

//---------------------------------------------------------
// Fuel Collector
constexpr int FUEL_METER_F_PORT = 4;
constexpr int FUEL_METER_B_PORT = 5;
constexpr int FUEL_INTAKE_PORT = 5;
constexpr double FUEL_INTAKE_SPEED = -.9;

//---------------------------------------------------------
// Input
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

//--------------------------------------------------------
// Motion Magic

constexpr double MAGIC_DEFAULT_RAMP = 240; // RPM/s
constexpr double MAGIC_DEFAULT_CRUISE = 240; //RPM
constexpr double MAGIC_FINISH_WAIT_TIME = .5; // not tuned

constexpr double MAGIC_ROT_PER_DEG = 0.0284;
constexpr double MAGIC_IN_PER_ROT = 18.8;
constexpr double MAGIC_ENC_TO_DRIVE_RATIO = 2.165;

constexpr double MAGIC_PI = 3.14159265;
constexpr double MAGIC_ROBOT_WIDTH = 33;

// Summary:
// Per motor profile data
struct pr_data_t
{
	double distance;
	double ramp;
	double cruise;
};

// Summary:
// Structure for drivetrain motion magic data
struct Profile
{
	pr_data_t left;
	pr_data_t right;

	bool isEmpty;

	Profile(double leftD, double rightD) :
		isEmpty(false)
	{
		left.distance = leftD;
		left.ramp = MAGIC_DEFAULT_RAMP;
		left.cruise = MAGIC_DEFAULT_CRUISE;

		right.distance = rightD;
		right.ramp = MAGIC_DEFAULT_RAMP;
		right.cruise = MAGIC_DEFAULT_CRUISE;
	}

	Profile(double leftD, double rightD, double ramp, double cruise) :
		isEmpty(false)
	{
		left.distance = leftD;
		right.distance = rightD;

		left.ramp = ramp;
		right.ramp = ramp;
		left.cruise = cruise;
		right.cruise = cruise;
	}

	Profile(pr_data_t l, pr_data_t r) :
		left(l), right(r) {}

	Profile() :
		isEmpty(true) {}
};

// Creates profile data for a motor
inline pr_data_t create_pr_data(double distance, double ramp, double cruise)
{
	pr_data_t data;
	data.distance = distance;
	data.ramp = ramp;
	data.cruise = cruise;
	return data;
}

// Construct a profile to turn, on center, a set degree and direction
// + = right; - = left NOT CONFIRMED
inline Profile make_profile_turn(
		double degrees,
		double ramp = MAGIC_DEFAULT_RAMP,
		double cruise = MAGIC_DEFAULT_CRUISE)
{
	return Profile(MAGIC_ROT_PER_DEG * degrees, MAGIC_ROT_PER_DEG * degrees, ramp, cruise);
}

// Construct a profile from target distance in inches
inline Profile make_profile_inches(
		double inches,
		double ramp = MAGIC_DEFAULT_RAMP,
		double cruise = MAGIC_DEFAULT_CRUISE)
{
	double dist = inches / MAGIC_IN_PER_ROT * MAGIC_ENC_TO_DRIVE_RATIO;
	return Profile(dist, -dist, ramp, cruise);
}

// Construct a profile to turn an arc
// radius in inches
inline Profile make_profile_arc(
		double radius,
		double degrees,
		bool reverse = false,
		double ramp = MAGIC_DEFAULT_RAMP,
		double cruise = MAGIC_DEFAULT_CRUISE)
{
	// Needs to change speed as well
	double oDist = (reverse ? -1 : 1) * 2 * MAGIC_PI * (radius + MAGIC_ROBOT_WIDTH / 2) * std::abs(degrees) / 360;
	double iDist = (reverse ? -1 : 1) * 2 * MAGIC_PI * (radius - MAGIC_ROBOT_WIDTH / 2) * std::abs(degrees) / 360;

	double oVel = (oDist / radius * 2) * cruise;
	double iVel = (iDist / radius * 2) * cruise;

	double oRamp = (oDist / radius * 2) * ramp;
	double iRamp = (iDist / radius * 2) * ramp;

	return Profile(
			(degrees >= 0) ? create_pr_data(oDist, oRamp, oVel) : create_pr_data(iDist, iRamp, iVel),
			(degrees >= 0) ? create_pr_data(iDist, iRamp, iVel) : create_pr_data(oDist, oRamp, oVel));
}

#define MAGIC_ZERO std::vector<Profile>{ Profile() }

// Distances
constexpr double MAGIC_BASELINE_CROSS = 85;
constexpr double MAGIC_PEG_PLACE = 25;
constexpr double MAGIC_PEG_RETRY = 12.0;
constexpr double MAGIC_PEG_BOILER = 81.5;
constexpr double MAGIC_PEG_MID = 79.5;
constexpr double MAGIC_PEG_GEAR = 87.0;
constexpr double MAGIC_PEG_PULLAWAY = 0.0; // unknown

//---------------------------------------------------------
// Utility Functions

// If a number is within a range rather than equal to
inline bool is_about(double target, double value, double acceptableRange)
{
	return value <= target + acceptableRange && value > target - acceptableRange;
}

// Wrapper for this_thread::sleep_for()
inline void sleep(uint timeMS)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(timeMS));
}

constexpr double LOG_RESOLUTION = 1;

#endif // ROBOT_MAP_H
