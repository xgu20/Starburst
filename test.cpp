#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;

int main() {
    std::string image_path = samples::findFile("../../EyeTrackingData/P1_10_pos.jpg");
    Mat img = imread(image_path, IMREAD_COLOR);
}