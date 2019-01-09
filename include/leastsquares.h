#ifndef LEASTSQUARES_H
#define LEASTSQUARES_H

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <include/matrix_operations.h>

using namespace cv;
typedef vector<Point> Contour;

class LeastSquares
{
private:
    Mat dataset;
    double slope;
    double intercept;
public:
    LeastSquares(Mat &input);
    LeastSquares(Contour &contour);
    double getSlope(){
        return slope;
    }
    double getIntercept(){
        return intercept;
    }
};

#endif // LEASTSQUARES_H
