#include "figure.h"
#include <cmath>

double figure::VectNorm(point l, point r) const {
    point vect = operator-(l, r);
    double res = sqrt(vect.x * vect.x + vect.y * vect.y);
    return res;
}
double figure::VectPropX(point l, point r) const {
    double res = l.x / r.x;
    return res;
}
double figure::VectPropY(point l, point r) const{
    double res = l.y / r.y ;
    return res;
}

double figure::ScalProd(point l, point r) const {
    return l.x * r.x + l.y * r.y;
}

double figure::COS(point l, point r) const {
    double res = ScalProd(l, r) / VectNorm(l, r);
    return res;
}

double figure::SIN(point l, point r) const {
    return sqrt(1 - pow(COS(l, r), 2));
}

double figure::TrArea(point a, point b, point c) const {
    return VectNorm(a,b) * VectNorm(a,c) * SIN(operator-(a,b), operator-(a,c));
}


