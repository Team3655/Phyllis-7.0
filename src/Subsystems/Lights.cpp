#include "Lights.h"
#include "../RobotMap.h"

//#include "../Commands/"

Lights::Lights() :
	frc::Subsystem("Lights")
{
}

void Lights::InitDefaultCommand()
{
	//SetDefaultCommand(new thing())
}

void Lights::Initialize()
{
	m_alliance = frc::DriverStation::GetInstance().GetAlliance();
	m_position = frc::DriverStation::GetInstance().GetLocation();
}

void Lights::DashboardOutput(bool verbose)
{
	frc::SmartDashboard::PutNumber("Location", m_position);

	if (verbose)
	{

	}
}
