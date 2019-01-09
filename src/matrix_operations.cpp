#include "include/matrix_operations.h"

void average(cv::Mat &src, float &avgX, float &avgY)
{
    avgX=0;
    avgY=0;
    pointsVector data = extractPoints(src);
    average(data, avgX, avgY);
}



pointsVector extractPoints(Mat &src)
{
    assert(src.type()==0);
    pointsVector data;
    for(int y(0);y<src.rows;y++){
        for(int x(0);x<src.cols;x++){
            if(src.at<int>(x,y)>0){
                data.push_back(pixelPair(x,y));
            }
        }
    }
    return data;
}

void average(pointsVector &src, float &avgX, float &avgY)
{
    avgX=0;
    avgY=0;
    for(auto pixel:src){
        avgX+=pixel.first;
        avgY+=pixel.second;
    }
}

void average(pixelVector &src, float &avgX, float &avgY)
{
    avgX=0;
    avgY=0;
    for(auto pixel:src){
        avgX+=pixel.x;
        avgY+=pixel.y;
    }
}
