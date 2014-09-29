//============================================================================
// Name        : reCon.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <stdio.h>

#include "reCon-lib.h"

using namespace std;
using namespace cv;

int main(int argc, const char** argv) {
	CvCapture* capture = 0;
	Mat frame, frameCopy, image;
	capture = cvCaptureFromCAM(CV_CAP_ANY); //0=default, -1=any camera, 1..99=your camera
	if (!capture) {
		cout << "No camera detected" << endl;
	}

	cvNamedWindow("result", CV_WINDOW_AUTOSIZE);

	if (capture) {
		cout << "In capture ..." << endl;
		for (;;) {
			IplImage* iplImg = cvQueryFrame(capture);
			frame = iplImg;

			if (frame.empty())
				break;
			if (iplImg->origin == IPL_ORIGIN_TL)
				frame.copyTo(frameCopy);
			else
				flip(frame, frameCopy, 0);

			Mat sobel;
			sobel = getSobel(frameCopy);
			namedWindow("result", 1);
			imshow("result", sobel);

			//printf("la imagen tiene %d por %d\n",bnw.cols,bnw.rows);
			/*
			 * Este bloque obtiene en formato rgb el color del punto x,y
			 int x, y, r, g, b;
			 x = 10;
			 y = 10;
			 Point3_<uchar>* p = bnw.ptr<Point3_<uchar> >(x,y);
			 r = p->z;
			 g = p->y;
			 b = p->x;
			 printf("el color en el punto %d, %d es %d %d %d\n", x, y, r, g, b);
			 */
			if (waitKey(10) >= 0)
				break;
		}
// waitKey(0);
	}

	cvReleaseCapture(&capture);
	cvDestroyWindow("result");

	return 0;
}
