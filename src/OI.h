#ifndef OI_H
#define OI_H

#include <Joystick.h>
#include <Buttons/JoystickButton.h>
#include "RobotMap.h"

// Summary:
//	Handles operator input
class OI
{
private:
	Joystick* m_driver;
	frc::JoystickButton* m_shift;

	Joystick* m_coDriver;
	frc::JoystickButton* m_shoot;
	frc::JoystickButton* m_manualOverride;

public:
	OI();
	~OI();

	Joystick* GetDriver() { return m_driver; }
	Joystick* GetCoDriver() { return m_coDriver; }

	// Temporary
	double GetAxisX() { return m_driver->GetAxis(Joystick::AxisType::kXAxis); }
	double GetAxisY() { return m_driver->GetAxis(Joystick::AxisType::kYAxis); }
};

#endif  // OI_H
