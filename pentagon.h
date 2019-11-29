//
// Created by Вова on 04.11.2019.
//
#include <cmath>
#include "figure.h"
#ifndef LAB3_PENTAGON_H
#define LAB3_PENTAGON_H
class pentagon : public figure {
public:
    pentagon();
    pentagon(const point& a, const point& b, const point& c, const point& d, const point& e);
    pentagon(std::istream& is);
    double area() const override;
    point center() const override;
    std::ostream& print(std::ostream& os) const override;
private:
    point a_;
    point b_;
    point c_;
    point d_;
    point e_;
};

#endif LAB3_PENTAGON_H //PENTAGON
