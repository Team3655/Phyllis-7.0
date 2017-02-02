#ifndef LIGHTS_H
#define LIGHTS_H

#include <Commands/Subsystem.h>
#include <DriverStation.h>

#include "../ExtSubsystem.h"

// Summary:
//	Controls indicators (mainly lights) for robot feedback
class Lights : public frc::Subsystem, public ExtSubsystem
{
private:
	frc::DriverStation::Alliance m_alliance;
	int m_position;

public:
	Lights();
	void InitDefaultCommand();

	void Initialize() override;
	void DashboardOutput(bool verbose = false) override;

	inline bool IsBlue() { return m_alliance == frc::DriverStation::Alliance::kBlue; }
	inline bool IsRed() { return m_alliance == frc::DriverStation::Alliance::kRed; }
	inline int GetLocation() { return m_position; }
};

#endif // LIGHTS_H
