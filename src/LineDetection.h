#ifndef LINEDETECTION_H
#define LINEDETECTION_H

#include "Detection.h"
#include <opencv2/core/mat.hpp>
#include <string>

class LineDetection : public Detection {
public:
    LineDetection();
    ~LineDetection() override;

    void detectFeatures(const cv::Mat& image) override;
    //void writeFeatures(const std::string& filename) const override;
    void displayFeatures() const override;

    int getLowThreshold() const;
    int getHighThreshold() const;
    int getKernelSize() const;
    void setLowThreshold(int lowThreshold);
    void setHighThreshold(int highThreshold);
    void setKernelSize(int kernelSize);
    static void TrackbarCallback(int, void* userdata);
    void detectFeaturesWithTrackbar(const Mat& inputImage);
private:
    int lowThreshold;
    int highThreshold;
    int kernelSize;
    Mat inputImage;
};

#endif // LINEDETECTION_H
