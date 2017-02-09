#include "CollectFuel.h"

CollectFuel::CollectFuel()
{
	Requires(fuelCollector.get());

	int code = oi.get()->GetPrefs()->GetInt("joy_btn_fuel_end_intake");
	m_endBtn = new frc::JoystickButton(oi.get()->GetStick(oi.get()->InterpretStick(code)), oi.get()->InterpretButton(code));
}

void CollectFuel::Initialize()
{
	m_speed = oi.get()->GetPrefs()->GetDouble("fuel_intake_speed", FUEL_INTAKE_SPEED);
}

void CollectFuel::Execute()
{
	fuelCollector.get()->SetIntake(m_speed);
}

bool CollectFuel::IsFinished()
{
	return m_endBtn->Get();
}

void CollectFuel::End()
{
	fuelCollector.get()->SetIntake(0);
}

void CollectFuel::Interrupted()
{
}
