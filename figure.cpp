#include "figure.h"
#include <cmath>

double figure::VectNorm(point l, point r) const {
    point vect = operator-(l, r);
    double res = sqrt(vect.x * vect.x + vect.y * vect.y);
    return res;
}
double figure::VectPropX(point l, point r) const {
    double res;
    if (l.x == 0 || r.x == 0) {
        res = 0;
    } else {
        res = l.x / r.x;
    }
    return res;
}
double figure::VectPropY(point l, point r) const{
    double res;
    if (l.y == 0 || r.y == 0) {
        res = 0;
    } else {
        res = l.y / r.y ;
    }
    return res;
}

double figure::ScalProd(point l, point r) const {
    return std::abs(l.x * r.x + l.y * r.y);
}
double::figure::TrAngle(point a, point b, point c) const {
     point  v1, v2;
     v1 = operator-(a, b);
     v2 = operator-(a, c);
     return std::abs(v1.x * v2.y - v2.x * v1.y) / 2;
}


