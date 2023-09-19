#include <iostream>
#include "remove_corneal_reflection.h"


void locate_corneal_reflection(cv::Mat& image, cv::Mat& threshold_image, 
    int sx, int sy, int window_size, 
    int biggest_crar, int &crx, int &cry, int &crar) {
    if (window_size%2 == 0) {
        printf("Error! window_size should be odd!\n");
    }
    int r = (window_size-1)/2;
    int startx = MAX(sx-r, 0);
    int endx = MIN(sx+r, image->width-1);
    int starty = MAX(sy-r, 0);
    int endy = MIN(sy+r, image->height-1);
    cv::Rect roi = cv::Rect(startx, starty, endx-startx+1, endy-starty+1);

    cv::Mat image_roi, threshold_image_roi;
    roiImg = image(roi);
    threshold_image_roi = threshold_image(roi);

    double min_value, max_value;
    cv::Point min_loc, max_loc
    cv::minMaxLoc(image_roi, &min_value, &max_value, &min_loc, &max_loc);
    vector<vector<cv::Point>> contours;

    int threshold, i;
    for (threshold = (int)max_value; threshold >= 1; threshold--) {
        cv::threshold(image_roi, threshold_image_roi, threshold, 1, CV_THRESH_BINARY);
        cv::findContours(threshold_image_roi, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
    }

}