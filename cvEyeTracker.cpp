#include <opencv2/opencv.hpp>

#include <iostream>
using namespace cv;
using namespace std;

#define DEBUG

#define LOG(msg) \
    std::cout << __FILE__ << "(" << __LINE__ << "): " << msg << std::endl 

// image variables.
const char* imagePath = "../../EyeTrackingData/P1_10_pos.jpg";
cv::Mat eyeImage; 
int height = 0, width = 0;
vector<double> avg_intensity_hori;

const double beta = 0.2;	//hysteresis factor for noise reduction

int openImage(const char* path) {
    eyeImage = cv::imread(path, cv::IMREAD_GRAYSCALE);
    height = eyeImage.rows;
    width = eyeImage.cols;
    if (eyeImage.empty()) {
        LOG("Error opening image file");
        return -1;
    }

    // cv::imshow("Original Image", eyeImage);
    // cv::waitKey(0);

    return 0;
}

void Calculate_Avg_Intensity_Hori(cv::Mat& img) {
    avg_intensity_hori = vector<double>(height, 0.0);
    for (int row = 0; row < img.rows; ++row) {
        cv::Mat rowImage = img.row(row);  // 提取当前行
        double averageIntensity = cv::mean(rowImage)[0]; // 计算平均亮度
        avg_intensity_hori[row] = averageIntensity;
    }
}

int process_image() {

    // denoise image
    cv::Mat smoothed_image;
    cv::GaussianBlur(eyeImage, smoothed_image, cv::Size(5, 5), 0, 0);
#ifdef DEBUG
    cv::imwrite("smoothed_image.png", smoothed_image);
#endif
    // remove line noise if applicable

    // corneal reflection

    return 0;
}

int main() {
    int status;
    status = openImage(imagePath);
    if (status) {
        LOG("Error code: " + to_string(status));
    }
    status = process_image();
    return 0;
}
