#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// Drive
constexpr int DRIVE_LEFT_PORT = 1;
constexpr int DRIVE_RIGHT_PORT = 2;

// Input
#define CODRIVER  	// Use def check when referencing the co-driver stick
constexpr int JOY_DRIVER_PORT = 1;
constexpr int JOY_CODRIVER_PORT = 1;

// Camera
constexpr int CS_PORT = 0;

#endif  // ROBOTMAP_H
