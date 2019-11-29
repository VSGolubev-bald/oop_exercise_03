//
// Created by Вова on 04.11.2019.
//
#include "figure.h"
#ifndef LAB3_RHOMBUS_H
#define LAB3_RHOMBUS_H
class rhombus : public figure {
public:
    rhombus();
    rhombus(const point& a, const point& b, const point& c, const point& d);
    rhombus(std::istream& is);
    double area() const override;
    point center() const override;
    std::ostream& print(std::ostream& os) const override;
private:
    point a_;
    point b_;
    point c_;
    point d_;
};
#endif //LAB3_RHOMBUS_H
