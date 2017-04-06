#include "DelayCoast.h"

DelayCoast::DelayCoast(double delay)
{
	Requires(drive.get());
	Requires(lights.get());

	m_delay = delay;
	m_delayTimer = new frc::Timer();
}

void DelayCoast::Initialize()
{
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "Delay");
	drive.get()->Coast();
	m_delayTimer->Start();
}

void DelayCoast::Execute()
{
	lights.get()->SetColor(RED);
}

bool DelayCoast::IsFinished()
{
	return m_delayTimer->HasPeriodPassed(m_delay);
}

void DelayCoast::End()
{
	drive.get()->StopCoast();
	Logger::GetInstance()->Log("cmds", Logger::kExit, "Delay");
}

void DelayCoast::Interrupted()
{
	Logger::GetInstance()->Log("cmds", Logger::kInfo, "Delay interrupted");
}
