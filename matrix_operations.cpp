#include "matrix_operations.h"


double average(vector<float> &array){
    double average(0);
    int num(0);
    for(auto it : array){
        average+=static_cast<double>(it);
        num++;
    }
    return average/static_cast<double>(num);
}

void fillContour(const contour &original, pointVector &filled)
{
    int minx, maxx, miny, maxy;
    minMax(original, minx, miny, maxx, maxy);
    auto temp = Mat(maxy, maxx, CV_8UC1);
    fillConvexPoly(temp, original,Scalar(255));
    filled = extractPoints(temp);
}

pointVector extractPoints(Mat &src)
{
    assert(src.type()==0);
    pointVector data;
    for(int y(0);y<src.cols;y++){
        for(int x(0);x<src.rows;x++){
            if(src.at<int>(x,y)>0){
                data.push_back(Point(x,y));
            }
        }
    }
    return data;
}


void minMax(const contour &src, int &minX, int &minY, int &maxX, int &maxY)
{
    int x,y;
    minX = src.front().x;
    maxX = minX;
    minY = src.front().y;
    maxY = minY;

    for(auto point:src){
        x = point.x;
        y = point.x;
        if(x>maxX){
            maxX=x;
        }else if(x<minX){
            minX=x;
        }

        if(y>maxY){
            maxY=y;
        }else if (y<minY) {
            minY=y;
        }
    }
}
