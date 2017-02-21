#include "Turn.h"

Turn::Turn(double sd)
{
	Requires(drive.get());

	m_speedDirect = sd;
}

void Turn::Initialize()
{

}

void Turn::Execute()
{
	drive.get()->ArcadeDrive(0, m_speedDirect);
}

bool Turn::IsFinished()
{
	return false;
}

void Turn::End()
{

}

void Turn::Interrupted()
{

}
