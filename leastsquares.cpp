#include "leastsquares.h"


LeastSquares::LeastSquares()
{
    ;
}


LeastSquares::LeastSquares(Contour contour)
{
    int N(0);
    vector<double> x2;
    vector<double> y2;
    vector<double> xy;
    double kd, x, y, X2, Y2, XY;
    double X(0), Y(0);

    for(auto pixel=contour.begin();pixel!=contour.end();pixel++){
        N++;
        x = pixel->x;
        y = pixel->y;
        xy.push_back(x*y);
        x2.push_back(x*x);
        y2.push_back(y*y);
        X += x;
        Y += y;
    }
    XY = sum<double>(xy);
    X2 = sum<double>(x2);
    Y2 = sum<double>(y2);

    /*
     *      (NΣxy − ΣxΣy)
     * k = ----------------
     *      N(Σx2) − (Σx)^2
     */

    k = (N*XY - X*Y) / (N*X2 - (X*X));

    /*
     *      (NΣxy − ΣxΣy)
     * k' = ----------------
     *      N(Σy2) − (Σy)^2
     */

    kd = (N*XY - X*Y) / (N*Y2 - (Y*Y));

    /*
     *      Σy − m(Σx)
     * q = ------------
     *          N
     */
    q = (Y - k*X) / N;

    /* coefficient of determination
     *
     * R2 = k.k'
     */

    R2 =k*kd;
}

double LeastSquares::getX(double y)
{
    return (y-q) / k;
}

double LeastSquares::getY(double x)
{
    return (k*x + q);
}

