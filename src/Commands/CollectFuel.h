#ifndef COLLECT_FUEL_H
#define COLLECT_FUEL_H

#include "../CommandBase.h"

class CollectFuel : public CommandBase
{
private:
	frc::JoystickButton* m_collectBtn;

public:
	CollectFuel();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // COLLECT_FUEL_H
