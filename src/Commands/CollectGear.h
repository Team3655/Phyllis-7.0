#ifndef COLLECT_GEAR_H
#define COLLECT_GEAR_H

#include "../CommandBase.h"

class CollectGear : public CommandBase
{
private:
#ifdef TEMP
	frc::JoystickButton* m_intakeBtn;
#endif
	frc::JoystickButton* m_endBtn;

	bool m_direction;

public:
	CollectGear(bool direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // COLLECT_GEAR_H
