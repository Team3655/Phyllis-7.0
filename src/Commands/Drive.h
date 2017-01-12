///////////////////////////////////////////////////////////////////////////////
//
// Drive.h
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef DRIVE_H
#define DRIVE_H

#include "../CommandBase.h"
#include "../Subsystems/DriveTrain.h"

class Drive : public CommandBase
{
private:
	DriveTrain* m_drive;
	OI* m_oi;

public:
	Drive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DRIVE_H
