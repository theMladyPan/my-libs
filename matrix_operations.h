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


typedef vector<Point> pointVector;
typedef vector<Point> contour;

double average(vector<float> &array);

void fillContour(const contour &original, pointVector &filled);

void minMax(const contour &src, int &minX, int &minY, int &maxX, int &maxY);

pointVector extractPoints(Mat &src);


template<typename T>
T sum(vector<T> array)
{
    T n;
    for(auto &elem:array){
         n += elem;
    }
    return n;
}


#endif // MATRIX_OPERATIONS_H

