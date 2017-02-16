#ifndef WAIT_FOR_PEG_H
#define WAIT_FOR_PEG_H

#include "../CommandBase.h"

class WaitForPeg : public CommandBase
{
private:
	frc::JoystickButton* m_abortBtn;

public:
	WaitForPeg(frc::JoystickButton*);
	~WaitForPeg();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // WAIT_FOR_PEG_H
