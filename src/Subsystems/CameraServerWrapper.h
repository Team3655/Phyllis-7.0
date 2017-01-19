#ifndef CameraServerWrapper_H
#define CameraServerWrapper_H

#include <Commands/Subsystem.h>
#include <CameraServer.h>
#include <WpiLib.h>

//#include "../GripPipeline.h"

class CameraServerWrapper : public Subsystem
{
private:
	//CameraServer* m_camera;
	//cs::UsbCamera* m_usbCamera;
	//grip::GripPipeline* m_visionProc;

	//cs::CvSink* m_cvSink;
	//cv::Mat* m_currentFrame;

	bool m_isProc = false;


public:
	CameraServerWrapper();
	void InitDefaultCommand();

	inline bool IsProccessing() { return m_isProc; }

	void StartStream();
	void StartProc();
	void EndProc();

	// Called every iteration
	void Proccess();
};

#endif  // CameraServerWrapper_H
