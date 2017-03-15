#include "GripPipeline.h"
#include <cmath>
#include "RobotMap.h"

namespace grip {

GripPipeline::GripPipeline()
{
	timer = new frc::Timer();
}

/**
* Runs an iteration of the Pipeline and updates outputs.
*
* Sources need to be set before calling this method. 
*
*/
void GripPipeline::Process(cv::Mat& source)
{
	timer->Reset();
	timer->Start();

	// Resize
	if (source.empty())
	{
		std::cout << "nil" << std::endl;
		return;
	}
	cv::resize(source, resizeImageOutput, cv::Size(IMG_RESIZE_W, IMG_RESIZE_H));

	cv::Mat hslMat = source;
	cv::cvtColor(hslMat, hslMat, cv::COLOR_BGR2HSV);

	cv::Mat hslThreshold;
	std::cout << "color pre" << std::endl;
	//if (hslMat.empty()) return;
	//cv::cvtColor(hslMat, hslThreshold, cv::COLOR_BGR2GRAY);
	std::cout << "hsl pre" << std::endl;
	if (hslMat.empty()) return;
	cv::inRange(hslMat,
			cv::Scalar(IMG_HSL_HUE[0], IMG_HSL_LUM[0], IMG_HSL_SAT[0]),
			cv::Scalar(IMG_HSL_HUE[1], IMG_HSL_LUM[1], IMG_HSL_SAT[1]),
			hslThreshold);
	std::cout << "hsl post" << std::endl;

	// Contours
	findContours(hslThreshold, false, findContoursOutput);
	// Filter Contours
	filterContours(
			findContoursOutput,
			IMG_CONT_MIN_AREA,
			IMG_CONT_MIN_PERIM,
			IMG_CONT_MIN_WIDTH,
			IMG_CONT_MAX_WIDTH,
			IMG_CONT_MIN_HEIGHT,
			IMG_CONT_MAX_HEIGHT,
			IMG_CONT_SOLID,
			IMG_CONT_MAX_VERTEX,
			IMG_CONT_MIN_VERTEX,
			IMG_CONT_MIN_RATIO,
			IMG_CONT_MAX_RATIO,
			this->filterContoursOutput);

	targets.clear();
	for (int i = 0; i < filterContoursOutput.size(); i++)
	{
		targets.push_back(cv::boundingRect(this->filterContoursOutput[i]));
		//rectangle(hslThreshold, cv::Point(targets[i].x, targets[i].y), cv::Point(targets[i].width, targets[i].height),
				//cv::Scalar(255, 255, 255), 5);
	}

	source = hslThreshold;
	timer->Stop();
	procTime = timer->Get();
}

/**
 * Finds contours in an image.
 *
 * @param input The image to find contours in.
 * @param externalOnly if only external contours are to be found.
 * @param contours vector of contours to put contours in.
 */
void GripPipeline::findContours(cv::Mat& input, bool externalOnly, std::vector<std::vector<cv::Point>>& contours)
{
	std::vector<cv::Vec4i> hierarchy;
	contours.clear();
	cv::findContours(input, contours, hierarchy, externalOnly ? cv::RETR_EXTERNAL : cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);
}

/**
 * Filters through contours.
 * @param inputContours is the input vector of contours.
 * @param minArea is the minimum area of a contour that will be kept.
 * @param minPerimeter is the minimum perimeter of a contour that will be kept.
 * @param minWidth minimum width of a contour.
 * @param maxWidth maximum width.
 * @param minHeight minimum height.
 * @param maxHeight  maximimum height.
 * @param solidity the minimum and maximum solidity of a contour.
 * @param minVertexCount minimum vertex Count of the contours.
 * @param maxVertexCount maximum vertex Count.
 * @param minRatio minimum ratio of width to height.
 * @param maxRatio maximum ratio of width to height.
 * @param output vector of filtered contours.
 */
void GripPipeline::filterContours(
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
		std::vector<std::vector<cv::Point>>& output)
{
	std::vector<cv::Point> hull;
	output.clear();
	for (std::vector<cv::Point> contour : inputContours) {
		cv::Rect bb = cv::boundingRect(contour);
		if (bb.width < minWidth || bb.width > maxWidth) continue;
		if (bb.height < minHeight || bb.height > maxHeight) continue;
		double area = cv::contourArea(contour);
		if (area < minArea) continue;
		if (arcLength(contour, true) < minPerimeter) continue;
		cv::convexHull(cv::Mat(contour, true), hull);
		double solid = 100 * area / cv::contourArea(hull);
		if (solid < solidity[0] || solid > solidity[1]) continue;
		if (contour.size() < minVertexCount || contour.size() > maxVertexCount)	continue;
		double ratio = bb.width / bb.height;
		if (ratio < minRatio || ratio > maxRatio) continue;
		output.push_back(contour);
	}
}

bool grip::GripPipeline::getTarget(int idx, cv::Rect& rect)
{
	if (targets.size() <= 0) return false;
	rect = targets[idx];
	return true;
}

double grip::GripPipeline::getTargetCenterX(int idx)
{
	if (targets.size() < 2) return -2;
	double center = -2;
	cv::Rect r1 = targets[idx];
	cv::Rect r2 = targets[idx + 1];
	if (r1.x < r2.x) // NOTE: may be reversed
		center = (r1.x + r2.x +r2.width) / 2;
	else
		center = (r2.x + r1.x +r1.width) / 2;
	return center;
}

double grip::GripPipeline::getTargetCenterY(int idx)
{
	if (targets.size() <= 0) return -2;
	cv::Rect& r = targets[idx];
	return r.y + r.height / 2;
}

double grip::GripPipeline::getProcTime()
{
	return procTime * 1000;
}

double GripPipeline::getDistance()
{
	cv::Rect r;
	if (getTarget(0, r))
		return 0;
	return (stuff.targetHeight * (10/12) * CS_CAM_RES_Y) / (2 * r.height * (std::tan((float)stuff.angle)));
}

void GripPipeline::setStuff(grip::CameraStuff cs)
{
	stuff = cs;
}

} // end grip namespace
