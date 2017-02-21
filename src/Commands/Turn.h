#ifndef TURN_H
#define TURN_H

#include "../CommandBase.h"

// Summary:
//
class Turn : public CommandBase
{
private:
	double m_speedDirect;

public:
	Turn(double sd);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // TURN_H
