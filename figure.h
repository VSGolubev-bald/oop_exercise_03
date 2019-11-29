#include <iostream>
#include "point.h"
#include <cmath>
#ifndef LAB3_FIGURE_H
#define LAB3_FIGURE_H

struct figure {
    virtual point center() const = 0;
    virtual std::ostream& print(std::ostream &os) const = 0;
    virtual double area() const = 0;
    virtual ~figure() {};
    double VectNorm(point l, point r) const;
    double VectPropX(point l, point r) const;
    double VectPropY(point l, point r) const;
    double ScalProd(point l, point r) const;
    double COS(point l, point r) const;
    double SIN(point l, point r) const;
    double TrArea(point a, point b, point c) const;
};
#endif //OOP_EXERCISE_03_FIGURE_H

