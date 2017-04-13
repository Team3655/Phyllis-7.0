#ifndef SHOOT_H
#define SHOOT_H

#include <Timer.h>
#include <Buttons/JoystickButton.h>

#include "../CommandBase.h"

// Summary:
//	Fires all of the balls in the magazine unless something interrupts
class Shoot : public CommandBase
{
private:
	bool m_auton;
	double m_speedProportion;

	frc::Timer m_timer;

	frc::JoystickButton* m_abortBtn;
	frc::JoystickButton* m_meterBtn;

public:
	Shoot(double speedProp, bool auton = false);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // SHOOT_H
