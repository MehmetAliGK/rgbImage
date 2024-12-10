# **Feature Detection in RGB Images**

## **Overview**

This project implements a class-based design for detecting lines and corners in RGB images using OpenCV. The system uses a structured class hierarchy to handle image processing tasks and feature detection. The main functionalities include line detection using algorithms like Canny or Hough and corner detection using the Harris algorithm.

## **Features**

- Implements a modular class hierarchy:
  - CommonProcesses: Handles reading, writing, displaying, rescaling, noise filtering, and grayscale conversion of RGB images.
  - Detection: Base class for feature visualization and writing detected features (lines or corners) to a file.
  - Line Detection: Detects lines in images and provides access to detected lines in an STL container.
  - Corner Detection: Detects corners in images and provides access to detected corners in an STL container.
- Uses OpenCV for efficient image processing.
- Supports visualization of detected lines and corners.
- Provides easy-to-extend class design for additional functionalities.
## **Input Format**
The input image file should be in RGB format. The raw image data is processed to detect features (lines and corners).

## **Usage**
  1. Clone the repository:
  git clone https://github.com/MehmetAliGK/rgbImage.git  
  2. Compile the code using a C++ compiler with OpenCV linked:
  g++ main.cpp -o feature_detection `pkg-config --cflags --libs opencv4`  
  3. Run the program:
  ./feature_detection input_image.jpg  

## **File Structure**
- main.cpp: Contains the implementation of the feature detection system.
- CommonProcesses.h and CommonProcesses.cpp: Base class for common image processing tasks.
- Detection.h and Detection.cpp: Base class for feature visualization and file operations.
- LineDetection.h and LineDetection.cpp: Implementation of line detection functionality.
- CornerDetection.h and CornerDetection.cpp: Implementation of corner detection functionality.
- README.md: Project documentation.

## **Example Outputs**
- Line Detection: Detected lines are visualized and saved to a file.
- Corner Detection: Detected corners are visualized and saved to a file.

## **Dependencies**
- OpenCV library (ensure it is installed and properly linked).
