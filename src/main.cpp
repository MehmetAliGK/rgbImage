#include "CommonProcesses.h"
#include "LineDetection.h"
#include "CornerDetection.h"

int main() {  

    //Information about program
    cout << "Feature detection of a RGB image" << endl;

    string imagePath = "C:\\resim\\deneme.png"; //image path

// Initialize CommonProcesses for basic image operations
    CommonProcesses imageProcessor(imagePath);

// Display the original image
    imageProcessor.displayImage();

// Perform line detection
    LineDetection lineDetector;
    lineDetector.detectFeatures(imageProcessor.getImage());
    lineDetector.displayFeatures();

    // Perform corner detection
    CornerDetection cornerDetector;
    cornerDetector.detectFeatures(imageProcessor.getImage());
    cornerDetector.displayFeatures();

    return 0;
}
