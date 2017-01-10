///////////////////////////////////////////////////////////////////////////////
//
// CameraServerWrapper.cpp
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include "CameraServerWrapper.h"

CameraServerWrapper::CameraServerWrapper() :
	Subsystem("Camera Server")
{
	m_cameraServer = CameraServer::GetInstance();
}

