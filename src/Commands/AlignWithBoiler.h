#ifndef ALIGN_WITH_BOILER_H
#define ALIGN_WITH_BOILER_H

#include "../CommandBase.h"

class AlignWithBoiler : public CommandBase
{
private:
	frc::PIDController* m_pid;

public:
	AlignWithBoiler();
	~AlignWithBoiler();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // ALIGN_WITH_BOILER_H
