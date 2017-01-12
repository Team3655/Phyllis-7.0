///////////////////////////////////////////////////////////////////////////////
//
// CameraServerWrapper.h
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef CAMERA_SERVER_WRAPPER_H
#define CAMERA_SERVER_WRAPPER_H

#include <Wpilib.h>

// Summary:
//
class CameraServerWrapper : public frc::Subsystem
{
private:
	CameraServer* m_cameraServer;

public:
	CameraServerWrapper();
};

#endif // CAMERA_SERVER_WRAPPER_H
