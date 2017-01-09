///////////////////////////////////////////////////////////////////////////////
//
// CameraServerWrapper.h
//
//  Created on: Jan 7, 2017
//      Author: Si da Ag
//
///////////////////////////////////////////////////////////////////////////////

#ifndef CAMERA_SERVER_WRAPPER_H
#define CAMERA_SERVER_WRAPPER_H

#include <Wpilib.h>

//
class CameraServerWrapper : public Subsystem
{
private:
	CameraServer* m_cameraServer;

public:
	CameraServerWrapper();
};

#endif // CAMERA_SERVER_WRAPPER_H
