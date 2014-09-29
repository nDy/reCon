/*
 * reCon-lib.h
 *
 *  Created on: Sep 25, 2014
 *      Author: ndy
 */

#include "Robot.h"
#include <queue>
#include <opencv2/imgproc/imgproc.hpp>
#include "Vector2D.h"
#ifndef RECON_LIB_H_
#define RECON_LIB_H_

std::queue<Robot*>* getRobots(cv::Mat image) {
	std::queue<Robot*>* robots;
	robots = new std::queue<Robot*>();

	/*
	 detect(Image i){
	 compute Hn by edge extraction
	 compute Hn,l from histograms
	 for all(l)
	 compute feature vectors from histograms
	 compute segment S
	 for all (S)
	 compute probability
	 if (P(Si)>= threshold)
	 QR detection algorithm
	 endif
	 end for
	 end for
	 }
	 */

	return robots;
}

cv::Mat getSobel(cv::Mat src) {

	cv::Mat sobel;
	cv::Mat src_gray;
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;

	cv::GaussianBlur(src, src, cv::Size(3, 3), 0, 0, cv::BORDER_DEFAULT);

	/// Convert it to gray
	cv::cvtColor(src, src_gray, cv::COLOR_RGB2GRAY);

	/// Generate grad_x and grad_y
	cv::Mat grad_x, grad_y;
	cv::Mat abs_grad_x, abs_grad_y;

	/// Gradient X
	//cv::Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, cv::BORDER_DEFAULT );
	cv::Sobel(src_gray, grad_x, ddepth, 1, 0, 3, scale, delta,
			cv::BORDER_DEFAULT);
	cv::convertScaleAbs(grad_x, abs_grad_x);

	/// Gradient Y
	//cv::Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, cv::BORDER_DEFAULT );
	cv::Sobel(src_gray, grad_y, ddepth, 0, 1, 3, scale, delta,
			cv::BORDER_DEFAULT);
	cv::convertScaleAbs(grad_y, abs_grad_y);

	/// Total Gradient (approximate)
	cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, sobel);

	return sobel;
}

cv::Mat getScharr(cv::Mat src) {

	cv::Mat scharr;
	cv::Mat src_gray;
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;

	cv::GaussianBlur(src, src, cv::Size(3, 3), 0, 0, cv::BORDER_DEFAULT);

	/// Convert it to gray
	cv::cvtColor(src, src_gray, cv::COLOR_RGB2GRAY);

	/// Generate grad_x and grad_y
	cv::Mat grad_x, grad_y;
	cv::Mat abs_grad_x, abs_grad_y;

	/// Gradient X
	//cv::Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, cv::BORDER_DEFAULT );
	cv::Sobel(src_gray, grad_x, ddepth, 1, 0, 3, scale, delta,
			cv::BORDER_DEFAULT);
	cv::convertScaleAbs(grad_x, abs_grad_x);

	/// Gradient Y
	cv::Scharr(src_gray, grad_y, ddepth, 0, 1, scale, delta,
			cv::BORDER_DEFAULT);
	//cv::Sobel(src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, cv::BORDER_DEFAULT);
	cv::convertScaleAbs(grad_y, abs_grad_y);

	/// Total Gradient (approximate)
	cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, scharr);

	return scharr;
}

void getHOG(cv::Mat image, float threshold) {
	//get gradient orientation
	//return gradient matrix

	//Step 1:
	// Normalize gamma & color
/*
	[−1, 0, 1] gradient filter (not implemented yet, seems to be a good choice to improve O(t) )
	Scharr
	Sobel (first algorithm to take in consideration)
*/

	cv::Mat sobel = getSobel(image);

	//Step 2:
	// Compute Gradients

	cv::Mat gradients(sobel);

/*
	we calculate separate gradients for
	each colour channel, and take the one with the largest norm
	as the pixel’s gradient vector.
*/
	for (int i = 0; i < sobel.rows; ++i) {
		for (int j = 0; j < sobel.cols; ++j) {
			//gradients.at(i,j) = gradient
		}
	}


}

#endif /* RECON_LIB_H_ */
