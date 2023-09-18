#ifndef _REMOVE_CORNEAL_REFLECTION_H
#define _REMOVE_CORNEAL_REFLECTION_H

#define UINT8 unsigned char
#ifndef PI
#define PI 3.141592653589
#endif

#include <opencv2/opencv.hpp>


void remove_corneal_reflection(cv::Mat& image, cv::Mat& threshold_image, int sx, int sy, int window_size, 
     int biggest_crr, int &crx, int &cry, int& crr);

void locate_corneal_reflection(cv::Mat& image, cv::Mat& threshold_image, int sx, int sy, int window_size, 
     int biggest_crar, int &crx, int &cry, int &crar);

int fit_circle_radius_to_corneal_reflection(cv::Mat& image, int cx, int cy, int crar, int biggest_crar, 
    double *sin_array, double *cos_array, int array_len);

void interpolate_corneal_reflection(cv::Mat& image, int cx, int cy, int crr, double *sin_array, 
    double *cos_array, int array_len);

#endif
