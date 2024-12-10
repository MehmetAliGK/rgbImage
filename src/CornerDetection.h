#ifndef CORNERDETECTION_H
#define CORNERDETECTION_H

#include "Detection.h"

class CornerDetection : public Detection {
public:
    CornerDetection();
    ~CornerDetection() override;

    void detectFeatures(const Mat& image) override;
    void displayFeatures() const override;

    // Getters and Setters for Harris detector parameters
    int getBlockSize() const;
    double getK() const;
    int getThreshold() const;
    void setBlockSize(int blockSize);
    void setK(double k);
    void setThreshold(int threshold);

private:
    int blockSize; // Neighborhood size for corner detection
    double k;      // Harris detector free parameter
    int threshold; // Threshold for detecting corners
};

#endif // CORNERDETECTION_H
