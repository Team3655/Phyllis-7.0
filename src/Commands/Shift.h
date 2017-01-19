#ifndef Shift_H
#define Shift_H

#include "../CommandBase.h"

class Shift : public CommandBase
{
private:

public:
	Shift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Shift_H
