#include "SwitchCamera.h"

SwitchCamera::SwitchCamera()
{
	Requires(visionManager.get());
	Requires(lights.get());
}

void SwitchCamera::Initialize()
{
}

void SwitchCamera::Execute()
{
	int id = visionManager.get()->GetCurrentCam();
	if (id == CS_CAM_PEG_PORT)
	{
		visionManager.get()->SwitchCamera(CS_CAM_SHOOT_PORT);
		lights.get()->SetPegCamLight(true);
		lights.get()->SetShootCamLight(false);
	}
	else
	{
		visionManager.get()->SwitchCamera(CS_CAM_PEG_PORT);
		lights.get()->SetPegCamLight(false);
		lights.get()->SetShootCamLight(true);
	}
}

bool SwitchCamera::IsFinished()
{
	return true;
}

void SwitchCamera::End()
{
}

void SwitchCamera::Interrupted()
{
}
