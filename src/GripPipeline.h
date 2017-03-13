#pragma once
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/contrib/contrib.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <math.h>
#include <Timer.h>
#include <CameraServer.h>

namespace grip {

// Summary:
//
struct CameraStuff
{
	double targetHeight;
	double angle;

	CameraStuff(double height, double angle)
	{
		targetHeight = height;
		this->angle = angle;
	}

	CameraStuff()
	{
		targetHeight = 0;
		this->angle = 0;
	}
};

#define PEG	grip::CameraStuff(CS_TARGET_PEG_HEIGHT, CS_CAM1_HORIZON_ANGLE, grip::Target::kPeg)

// Summary:
//
class GripPipeline
{
	public:
		cv::Mat resizeImageOutput;
		cv::Mat hslThresholdOutput;

		std::vector<std::vector<cv::Point>> findContoursOutput;
		std::vector<std::vector<cv::Point>> filterContoursOutput;
		std::vector<cv::Rect> targets;

		frc::Timer* timer;
		double procTime;

		CameraStuff stuff;

		void findContours(cv::Mat&, bool, std::vector<std::vector<cv::Point>>&);
		void filterContours(
				std::vector<std::vector<cv::Point>>& inputContours,
				const double minArea,
				const double minPerimeter,
				const double minWidth,
				const double maxWidth,
				const double minHeight,
				const double maxHeight,
				const double solidity[],
				const double maxVertexCount,
				const double minVertexCount,
				const double minRatio,
				const double maxRatio,
				std::vector<std::vector<cv::Point>>& output);

	public:
		GripPipeline();
		void Process(cv::Mat source);
		bool getTarget(int, cv::Rect&);
		double getTargetCenterX(int);
		double getTargetCenterY(int);
		double getProcTime();
		double getDistance();

		cv::Mat& getProcessedFrame() { return hslThresholdOutput; }

		int getTargets() { return targets.size(); }

		void setStuff(grip::CameraStuff cs);
};


} // end namespace grip


