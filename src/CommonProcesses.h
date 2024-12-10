#ifndef COMMONPROCESSES_H
#define COMMONPROCESSES_H

#include <opencv2/opencv.hpp>
#include <string>
using namespace std;
using namespace cv;
class CommonProcesses {
public:
    explicit CommonProcesses(const string& filename);
    void displayImage() const;
    void writeImage(const string& filename);
    void rescaleImage(double scale);
    void filterNoise();
    void convertToGrayscale();
    const Mat& getImage();

private:
    Mat image;
    Mat rawImage;   
};

#endif 
    
