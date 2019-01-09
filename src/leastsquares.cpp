#include "include/leastsquares.h"


LeastSquares::LeastSquares(Mat &input)
{
    float avgX(0);
    float avgY(0);
    double sumProdXY(0);
    double sumXSqrd(0);

    average(input, avgX, avgY);
    pixelVector data = extractPoints(input);

    for(auto pair=data.begin();pair!=data.end();pair++){
        // Xm = xi - mean(X)
        float Xm = static_cast<float>(pair->first)-avgX;
        // Ym = yi - mean(Y)
        float Ym = static_cast<float>(pair->second)-avgY;
        // product = Xm * Ym
        float product = Xm*Ym;

        sumProdXY += static_cast<double>(product);
        sumXSqrd += pow(Xm,2);
    }

    // slope = sum(Xm, Ym)/sum(Xm^2)
    slope = sumProdXY/sumXSqrd;
    // intercept = mean(Y) − slope * mean(X)
    intercept = static_cast<double>(avgY) - (slope*static_cast<double>(avgX));

}

LeastSquares::LeastSquares(Contour contour)
{
    float avgX(0);
    float avgY(0);
    double sumProdXY(0);
    double sumXSqrd(0);

    average(contour, avgX, avgY);

    for(auto pixel=contour.begin();pixel!=contour.end();pixel++){
        // Xm = xi - mean(X)
        float Xm = static_cast<float>(pixel->x)-avgX;
        // Ym = yi - mean(Y)
        float Ym = static_cast<float>(pixel->y)-avgY;
        // product = Xm * Ym
        float product = Xm*Ym;

        sumProdXY += static_cast<double>(product);
        sumXSqrd += pow(Xm,2);
    }

    // slope = sum(Xm, Ym)/sum(Xm^2)
    slope = sumProdXY/sumXSqrd;
    // intercept = mean(Y) − slope * mean(X)
    intercept = static_cast<double>(avgY) - (slope*static_cast<double>(avgX));
}
