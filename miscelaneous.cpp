#include "miscelaneous.h"


Color::Color()
{
    rng = RNG(rand()%10000);
}

Color Color::setup(const int min, const int max)
{
    this->min = min;
    this->max = max;
    return *this;
}

Scalar Color::randomColor()
{
    return Scalar(rng.uniform(min,max), rng.uniform(min,max), rng.uniform(min,max));
}

Scalar Color::randomMono()
{
    return Scalar(rng.uniform(min,max));
}

Scalar Color::getColor(const int color)
{
    return Scalar(color/(256*256), (color%(256*256))/256, color%256);
}

int showCvMat(string name, Mat &inpArr, int delay_ms){
    namedWindow(name, WINDOW_NORMAL);       // Create a window for display.
    imshow(name, inpArr);                   // Show our image inside it.
    return waitKey(delay_ms);
}

void drawColorContours(const Mat &destArray, const vector<contour> &contours, const vector<Vec4i> &hierarchy){
    for( size_t i = 0; i< contours.size(); i++ )
    {
        auto color = Color().randomColor();
        drawContours( destArray, contours, (int)i, color, 1, LINE_AA, hierarchy, 0);
    }
}

void drawColorContours(const Mat &destArray, const vector<contour> &contours, const vector<Vec4i> &hierarchy, const Scalar color)
{
    for( size_t i = 0; i< contours.size(); i++ )
    {for( size_t i = 0; i< contours.size(); i++ )
        {
            drawContours( destArray, contours, (int)i, color, 1, LINE_AA, hierarchy, 0);
        }
        drawContours( destArray, contours, (int)i, color, 1, LINE_AA, hierarchy, 0);
    }
}

void drawPointVector(Mat &image, const pointVector &points, const Scalar &color, const int thickness, const int lineType){
    for(auto point:points){
        image.at<Scalar>(point.x, point.y) = color;
    }
}


void filterContours(const vector<contour> &original, vector<contour> &filtered, const long unsigned int minSize, const long unsigned int maxSize){
    for(auto vec=original.begin(); vec!=original.end(); vec++){
        if(vec->size()>minSize && vec->size() < maxSize){
              filtered.push_back(*vec);
          }
    }
}
