#ifndef		OBSTACLE_DETECTION_H
#define		OBSTACLE_DETECTION_H


#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "ObstacleDetection.cpp"



void	initGlobals();
void	skySegment(IplImage *frame);
bool	selectHorizonLineByCost(IplImage* img, CvPoint p1, CvPoint p2);
CvPoint	findHorizon(IplImage *img);
void	avoidDirection(IplImage *img, CvPoint delta);
void	cleanUp();


extern bool  output;
extern bool  flag;

#endif
