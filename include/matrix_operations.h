#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <vector>
#include <utility>

using namespace cv;
using namespace std;

typedef pair<int, int> pixelPair;
typedef vector<pair<int, int>> pointsVector;
typedef vector<Point> pixelVector;

void average(pixelVector &src, float &avgX, float &avgY);
void average(pointsVector &src, float &avgX, float &avgY);
void average(Mat &src, float &avgX, float &avgY);
pointsVector extractPoints(Mat &src);

#endif // MATRIX_OPERATIONS_H

