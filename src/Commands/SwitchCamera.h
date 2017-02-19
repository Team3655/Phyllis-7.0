#ifndef SWITCH_CAMERA_H
#define SWITCH_CAMERA_H

#include "../CommandBase.h"

// Summary:
//
class SwitchCamera : public CommandBase
{
public:
	SwitchCamera();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // SWITCH_CAMERA_H
