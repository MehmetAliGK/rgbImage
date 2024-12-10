#include "CommonProcesses.h"
#include <stdexcept>

CommonProcesses::CommonProcesses(const string& filename) {
    image = imread(filename, IMREAD_GRAYSCALE);
    rawImage = imread(filename, IMREAD_ANYCOLOR);
    if (image.empty()) {
        throw runtime_error("Image not found or unable to open");
    }
}

void CommonProcesses::displayImage() const {
    imshow("Raw image", rawImage);
    waitKey(0);
}

void CommonProcesses::writeImage(const std::string& filename) {
    imwrite(filename, image);
}

void CommonProcesses::rescaleImage(double scale) {
    resize(image, image, Size(), scale, scale);
}

void CommonProcesses::filterNoise() {
    GaussianBlur(image, image, Size(5, 5), 0);
}

void CommonProcesses::convertToGrayscale() {
    cvtColor(image, image, COLOR_BGR2GRAY);
}

const cv::Mat& CommonProcesses::getImage() {
    return image;
}


