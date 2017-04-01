#include "Lights.h"
#include "../RobotMap.h"

#include <SmartDashboard/SmartDashboard.h>

Lights::Lights() :
	frc::Subsystem("Lights"), ExtSubsystem(),
	m_color(OFF)
{
}

Lights::~Lights()
{
	m_log->Log(this, Logger::kExit);
	//delete m_red;
	//delete m_green;
	//delete m_blue;
}

void Lights::InitDefaultCommand()
{
}

void Lights::Initialize(frc::Preferences* prefs)
{
	m_log = Logger::GetInstance();
	m_log->AddLog(this);
	m_log->Log(this, Logger::kEnter);

	m_alliance = frc::DriverStation::GetInstance().GetAlliance();
	m_position = frc::DriverStation::GetInstance().GetLocation();

	m_pegCamLight = new frc::Solenoid(LIGHT_PEG_PORT);

	//m_red = new frc::Solenoid(LIGHT_RED_PORT);
	//m_green = new frc::Solenoid(LIGHT_GREEN_PORT);
	//m_blue = new frc::Solenoid(LIGHT_BLUE_PORT);
}

void Lights::DashboardOutput(bool verbose)
{
	frc::SmartDashboard::PutString("Light Color", m_color.name);
	frc::SmartDashboard::PutBoolean("Peg Light", m_pegCamLight->Get());

	if (verbose)
	{

	}
}

void Lights::SetPegCamLight(bool on)
{
	m_pegCamLight->Set(on);
	m_log->Log(this, Logger::kInfo, "Peg Light set to " + std::to_string(m_pegCamLight->Get()));
}

void Lights::SetShootCamLight(bool on)
{
	//m_shootCamLight->Set(on);
	//m_log->Log(this, Logger::kInfo, "Shoot Light set to " + std::to_string(m_shootCamLight->Get()));
}

void Lights::SetColor(const Color& color)
{
	//m_red->Set(color.red);
	//m_green->Set(color.green);
	//m_blue->Set(color.blue);
	m_color = color;

	//m_log->Log(this, Logger::kInfo, "Color set to " + m_color.name);
}
