#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "ObstacleDetection.h"
using namespace cv;
using namespace std;




int main(int argc, char** argv)
{

   string filename = "field_trees.mp4";
   VideoCapture cap(filename);
    if(!cap.isOpened())  // check if we succeeded
        return -1;


 


	// initialize and recieve input data

	//capture = cvCreateFileCapture("field_trees.mp4");
	//cvNamedWindow("Obstacle Detection");

    	Mat edges;
    	namedWindow("edges",1);
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera

		
	

        cvtColor(frame, edges, COLOR_BGR2GRAY);
        GaussianBlur(frame, frame, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 120, 3);
        imshow("edges", edges);
        if(waitKey(30) >= 0) break;


    }



	// cleanup and exit

    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
