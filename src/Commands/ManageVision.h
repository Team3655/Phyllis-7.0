#ifndef MANAGE_VISION_H
#define MANAGE_VISION_H

#include "../CommandBase.h"

class ManageVision : public CommandBase
{
private:
	frc::JoystickButton* m_switchCam;
	bool m_toggle;

public:
	ManageVision();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // MANAGE_VISION_H
