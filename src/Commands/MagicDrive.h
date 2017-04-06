#ifndef MAGIC_DRIVE_H
#define MAGIC_DRIVE_H

#include "../RobotMap.h"
#include "../Subsystems/DriveTrain.h"
#include "../CommandBase.h"

#include <memory>
#include <CANTalon.h>
#include <Timer.h>

// Summary:
//
class MagicDrive : public CommandBase
{
private:
	frc::Timer m_timer;

	Profile m_profile;

	std::shared_ptr<DriveTrain> m_drive;
	CANTalon* m_driveLeft;
	CANTalon* m_driveRight;

	CANTalon::TalonControlMode m_previousMode;

	bool m_triggered = false;

	bool is_finished();

public:
	MagicDrive(const Profile& pr);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // MAGIC_DRIVE_H
