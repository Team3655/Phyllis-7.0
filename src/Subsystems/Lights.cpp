#include "Lights.h"
#include "../RobotMap.h"

#include <SmartDashboard/SmartDashboard.h>

Lights::Lights() :
	frc::Subsystem("Lights"),
	m_color(OFF)
{
}

void Lights::InitDefaultCommand()
{
	//SetDefaultCommand(new ManageLights());
}

void Lights::Initialize(frc::Preferences* prefs)
{
	m_alliance = frc::DriverStation::GetInstance().GetAlliance();
	m_position = frc::DriverStation::GetInstance().GetLocation();

	m_red = new frc::Solenoid(LIGHT_RED_PORT);
	m_green = new frc::Solenoid(LIGHT_GREEN_PORT);
	m_blue = new frc::Solenoid(LIGHT_BLUE_PORT);
}

void Lights::DashboardOutput(bool verbose)
{
	frc::SmartDashboard::PutString("Color", m_color.name);

	if (verbose)
	{

	}
}

void Lights::SetColor(const Color& color)
{
	m_red->Set(color.red);
	m_green->Set(color.green);
	m_blue->Set(color.blue);
	m_color = color;
}
