#include "Delay.h"
#include "../Logger.h"

Delay::Delay(double delay)
{
	Requires(drive.get());
	Requires(lights.get());

	m_delay = delay;
}

void Delay::Initialize()
{
	Logger::GetInstance()->Log("cmds", Logger::kEnter, "Delay");
	drive.get()->Disable();
	m_delayTimer.Start();
}

void Delay::Execute()
{
	lights.get()->SetColor(RED);
}

bool Delay::IsFinished()
{
	return m_delayTimer.HasPeriodPassed(m_delay);
}

void Delay::End()
{
	drive.get()->Enable();
	m_delayTimer.Stop();
	m_delayTimer.Reset();
	Logger::GetInstance()->Log("cmds", Logger::kExit, "Delay");
}

void Delay::Interrupted()
{
	Logger::GetInstance()->Log("cmds", Logger::kInfo, "Delay interrupted");
}
