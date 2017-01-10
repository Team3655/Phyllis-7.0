#ifndef OI_H
#define OI_H

#include <Joystick.h>

class OI
{
private:
	Joystick* m_driver;
	Joystick* m_coDriver;

public:
	OI();

	Joystick* GetDriver() { return m_driver; }
	Joystick* GetCoDriver() { return m_coDriver; }

	// Temporary
	double GetAxisX() { return m_driver->GetAxis(Joystick::AxisType::kXAxis); }
	double GetAxisY() { return m_driver->GetAxis(Joystick::AxisType::kYAxis); }
};

#endif  // OI_H
