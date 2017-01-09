///////////////////////////////////////////////////////////////////////////////
//
// CameraServerWrapper.cpp
//
//  Created on: Jan 7, 2017
//      Author: Si da Ag
//
///////////////////////////////////////////////////////////////////////////////

#include "CameraServerWrapper.h"

CameraServerWrapper::CameraServerWrapper() :
	Subsystem("Camera Server")
{
	m_cameraServer = CameraServer::GetInstance();
}

