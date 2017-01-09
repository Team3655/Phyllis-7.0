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
};

#endif  // OI_H
