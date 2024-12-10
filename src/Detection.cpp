#include "Detection.h"
#include <fstream>

// This method should visualize the features, to be implemented specifically in derived classes.
void Detection::displayFeatures() const {
    imshow("Features", imageWithFeatures);
    waitKey(0);
}
