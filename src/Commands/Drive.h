///////////////////////////////////////////////////////////////////////////////
//
// Drive.h
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef Drive_H
#define Drive_H

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

#endif  // Drive_H
