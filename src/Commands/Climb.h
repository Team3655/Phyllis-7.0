#ifndef CLIMB_H
#define CLIMB_H

#include "../CommandBase.h"
#include <Buttons/JoystickButton.h>

class Climb : public CommandBase
{
private:
	frc::JoystickButton* m_thisBtn;

public:
	Climb(frc::JoystickButton*);
	~Climb();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // CLIMB_H
