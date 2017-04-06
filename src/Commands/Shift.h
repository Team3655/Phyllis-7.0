#ifndef SHIFT_H
#define SHIFT_H

#include "../CommandBase.h"

// Summary:
//	Toggles between low and high gear on the drive train
class Shift : public frc::InstantCommand
{
public:
	Shift();
	void Initialize();
};

#endif // SHIFT_H
