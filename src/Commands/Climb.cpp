#include "Climb.h"

Climb::Climb(frc::JoystickButton* thisBtn)
{
	Requires(climber.get());

	m_thisBtn = thisBtn;

}

Climb::~Climb()
{
}

void Climb::Initialize()
{
}

void Climb::Execute()
{
	climber.get()->SetSpeed(-CLIMB_SPEED);
}

bool Climb::IsFinished()
{
	return !m_thisBtn->Get();
}

void Climb::End()
{
	climber.get()->SetSpeed(0);
}

void Climb::Interrupted()
{
}
