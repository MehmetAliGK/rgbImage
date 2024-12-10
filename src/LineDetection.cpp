#include "LineDetection.h"
#include <vector>

// Constructor
LineDetection::LineDetection() : lowThreshold(50), highThreshold(150), kernelSize(3) {}

// Destructor
LineDetection::~LineDetection() {}

void LineDetection::TrackbarCallback(int, void* userdata) {
    LineDetection* ld = reinterpret_cast<LineDetection*>(userdata);
    ld->detectFeatures(ld->inputImage);
    imshow("Detected Lines", ld->imageWithFeatures);
}

// Member function for edge detection with trackbar for the threshold
void LineDetection::detectFeaturesWithTrackbar(const Mat& inputImage) {
    this->inputImage = inputImage;
    namedWindow("Detected Lines", 1);
    createTrackbar("Min Threshold:", "Detected Lines", &lowThreshold, 255, LineDetection::TrackbarCallback, this);
    TrackbarCallback(0, this); // Initial call for default settings
    waitKey(0);
}

// detectFeatures to be usable with the trackbar callback
void LineDetection::detectFeatures(const Mat& inputImage) {
    Mat edges;
    Canny(inputImage, edges, lowThreshold, highThreshold, kernelSize);
    edges.convertTo(edges, CV_8U);

    imageWithFeatures = inputImage.clone();
    cvtColor(imageWithFeatures, imageWithFeatures, COLOR_GRAY2BGR);
    imageWithFeatures.setTo(Scalar(255, 255, 255), edges); // Overlay edges in white
}

// Display the features
void LineDetection::displayFeatures() const {
    imshow("Detected Lines", imageWithFeatures);
    waitKey(0);
}

// Setters
void LineDetection::setLowThreshold(int lt)
{
    lowThreshold = lt;
}
void LineDetection::setHighThreshold(int ht)
{
    highThreshold = ht;
}
void LineDetection::setKernelSize(int ks)
{
    kernelSize = ks;
}

// Getters
int LineDetection::getLowThreshold() const 
{ 
    return lowThreshold; 
}
int LineDetection::getHighThreshold() const 
{ 
    return highThreshold; 
}
int LineDetection::getKernelSize() const 
{ 
    return kernelSize; 
}

