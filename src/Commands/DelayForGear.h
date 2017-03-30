#ifndef DELAY_FOR_GEAR_H
#define DELAY_FOR_GEAR_H

#include "../CommandBase.h"

// Summary:
// Command that delays if the gear is gone
class DelayForGear : public CommandBase
{
private:
	frc::Timer* m_timer;
	bool m_end;

public:
	DelayForGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // DELAY_FOR_GEAR_H
