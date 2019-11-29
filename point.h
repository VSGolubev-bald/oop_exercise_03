#include <iostream>
#ifndef LAB3_POINT_H
#define LAB3_POINT_H
struct point {
    double x, y;
};
point operator+(point l, point r);
point operator-(point l, point r);
point operator*(point p, double a);
point operator/(point p, double a);
std::istream &operator>>(std::istream &is, point &p);
std::ostream &operator<<(std::ostream &os, const point &p);

#endif //LAB3_POINT_H
