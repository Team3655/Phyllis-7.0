#ifndef CLIMBER_H
#define CLIMBER_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>

#include "../ExtSubsystem.h"

// Summary:
//
class Climber : public frc::Subsystem, public ExtSubsystem
{
private:
	enum ClimbState
	{
		kDown = 0,
		kClimbing = 1,
		kUp = 2
	} m_state;

	CANTalon* m_climbLeft;
	CANTalon* m_climbRight;

	std::string state_to_string(uint32_t state);

public:

	Climber();
	~Climber();
	void InitDefaultCommand();

	void Initialize() override;
	void DashboardOutput(bool verbose = false) override;
};

#endif  // CLIMBER_H
