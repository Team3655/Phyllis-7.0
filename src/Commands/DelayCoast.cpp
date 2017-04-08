#include "DelayCoast.h"

DelayCoast::DelayCoast(double delay)
{
	Requires(drive.get());
	Requires(lights.get());

	m_delay = delay;
}

void DelayCoast::Initialize()
{
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "Coast");
	drive.get()->Coast();
	m_delayTimer.Start();
}

void DelayCoast::Execute()
{
	lights.get()->SetColor(RED);
}

bool DelayCoast::IsFinished()
{
	return m_delayTimer.HasPeriodPassed(m_delay);
}

void DelayCoast::End()
{
	drive.get()->StopCoast();
	m_delayTimer.Stop();
	m_delayTimer.Reset();
	Logger::GetInstance()->Log("cmds", Logger::kExit, "Coast");
}

void DelayCoast::Interrupted()
{
	Logger::GetInstance()->Log("cmds", Logger::kInfo, "Coast interrupted");
}
