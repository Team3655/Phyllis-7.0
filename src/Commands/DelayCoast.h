#ifndef DELAY_COAST_H
#define DELAY_COAST_H

#include "../CommandBase.h"

// Summary:
// Coast the drive for a pecified period of time
class DelayCoast : public CommandBase
{
private:
	double m_delay;

	frc::Timer* m_delayTimer;

public:
	DelayCoast(double delay);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // DELAY_COAST_H
