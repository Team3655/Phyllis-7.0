#ifndef OI_H
#define OI_H

#include <Joystick.h>
#include <Buttons/JoystickButton.h>
#include <Preferences.h>
#include "RobotMap.h"

// Summary:
//	Handles operator input
class OI
{
private:
	frc::Preferences* m_prefs;

	frc::Joystick* m_driver;
	frc::JoystickButton* m_shift;
	frc::JoystickButton* m_collectGear;
	frc::JoystickButton* m_ejectGear;

	frc::Joystick* m_coDriver;
	frc::JoystickButton* m_shoot;
	//frc::JoystickButton* m_manualOverride;

	frc::Joystick* m_board;

	double m_deadband;
	bool m_enableDeadband;

public:
	OI();
	~OI();

	frc::Preferences* GetPrefs() { return m_prefs; }

	frc::Joystick* GetStick(int stick);

	double GetXAxis(int stick);
	double GetYAxis(int stick);
	double GetZAxis(int stick);

	double Deadband(double input);
	void SetDeadband(double band);
	double GetDeadband() { return m_deadband; }
	void EnableDeadband(bool enable) { m_enableDeadband = enable; }
};

#endif // OI_H
