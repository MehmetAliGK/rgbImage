#include "CornerDetection.h"
using namespace std;
using namespace cv;
CornerDetection::CornerDetection() : blockSize(2), k(0.04), threshold(200) {}

CornerDetection::~CornerDetection() {}

    // Harris corner detection
void CornerDetection::detectFeatures(const Mat& inputImage) {
    Mat dst, dst_norm;
    dst = Mat::zeros(inputImage.size(), CV_32FC1);
    cornerHarris(inputImage, dst, blockSize, 3, k);

    normalize(dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
    convertScaleAbs(dst_norm, imageWithFeatures);

    for (int i = 0; i < dst_norm.rows; i++) {
        for (int j = 0; j < dst_norm.cols; j++) {
            if ((int)dst_norm.at<float>(i, j) > threshold) {
                features.push_back(Vec4i(j, i, 0, 0)); // Store the corners
                circle(imageWithFeatures, Point(j, i), 5, Scalar(0), 2, 8, 0);
            }
        }
    }
}

void CornerDetection::displayFeatures() const {
    imshow("Detected Corners", imageWithFeatures);
    waitKey(0);
}

// Getters
int CornerDetection::getBlockSize() const 
{ 
    return blockSize; 
}
double CornerDetection::getK() const 
{ 
    return k; 
}
int CornerDetection::getThreshold() const 
{ 
    return threshold; 
}

// Setters
void CornerDetection::setBlockSize(int bSize) 
{ 
    blockSize = bSize; 
}
void CornerDetection::setK(double kValue) 
{ 
    k = kValue; 
}
void CornerDetection::setThreshold(int thresh) 
{ 
    threshold = thresh; 
}
