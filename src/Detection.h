#ifndef DETECTION_H
#define DETECTION_H

#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
using namespace std;
using namespace cv;
class Detection {
public:
    Detection() = default;
    virtual ~Detection() = default;

    virtual void detectFeatures(const Mat& image) = 0;
    //virtual void writeFeatures(const string& filename) const = 0;
    virtual void displayFeatures() const = 0;

protected:
    vector<Vec4i> features;      // This will store the lines or corners as needed
    Mat imageWithFeatures;       // This will store the image with drawn features for visualization
};

#endif // DETECTION_H
