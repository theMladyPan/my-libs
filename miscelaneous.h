#ifndef MISCELANEOUS_H
#define MISCELANEOUS_H

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stdio.h>


#define COLOR_WHITE     16777215
#define COLOR_BLUE      16711680
#define COLOR_GREEN     65280
#define COLOR_RED       255
#define COLOR_CYAN      16776960
#define COLOR_YELLOW    (COLOR_GREEN + COLOR_RED)

using namespace cv;
using namespace std;

typedef vector<Point> pointVector;
typedef vector<Point> contour;

/**
 * @brief The Color class provide simple generation of few basic colors
 */
class Color{
  private:
    RNG rng;
    int min = 0;
    int max = 255;

  public:
    /**
     * @brief Color initialize random seed
     */
    Color();

    /**
     * @brief setup change default min and max values for random generation. Higher values tend to be lighted, lower values tend to be darker
     * @param min is for minimal value
     * @param max is for maximal values
     */
    Color setup(const int min, const int max);

    /**
     * @brief randomColor provide scalar with random color
     * @return Scalar with 3 values (Color)
     */
    Scalar randomColor();
    /**
     * @brief randomMono provide scalar with single value, monochromatic
     * @return Scalar with one value (Mono)
     */
    Scalar randomMono();

    /**
     * @brief getColor provide scalar of desired color
     * @param color mnemonic, e.g. COLOR_RED
     * @return Scalar with desired color
     */
    Scalar getColor(const int color);
};

/**
 * @brief showCvMat shows openCV window
 * @param name string with name of window
 * @param inpArr cv::Mat to be shown
 * @param delay_ms delay to wait, default=0
 * @return key char of pressed key (if occured during delay)
 */
int showCvMat(string name, Mat &inpArr, int delay_ms=0);

/**
 * @brief drawColorContours
 * @param destArray
 * @param contours
 * @param hierarchy
 */
void drawColorContours(const Mat &destArray, const vector<contour> &contours, const vector<Vec4i> &hierarchy);

/**
 * @brief drawColorContours
 * @param destArray
 * @param contours
 * @param hierarchy
 * @param color
 */
void drawColorContours(const Mat &destArray, const vector<contour> &contours, const vector<Vec4i> &hierarchy, const Scalar color);

/**
 * @brief drawPointVector
 * @param image
 * @param points
 * @param color
 * @param thickness
 * @param lineType
 */
void drawPointVector(Mat &image, const pointVector &points, const Scalar &color, const int thickness, const int lineType);

/**
 * @brief filterContours
 * @param original
 * @param filtered
 * @param minSize
 */
void filterContours(const vector<contour> &original, vector<contour> &filtered, const long unsigned int minSize=0, const long unsigned int maxSize=INT32_MAX);

#endif // MISCELANEOUS_H
