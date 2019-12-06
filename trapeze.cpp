#include "trapeze.h"
#include <cmath>

trapeze::trapeze(): a_{0, 0}, b_{0, 0}, c_{0, 0}, d_{0, 0} {}
trapeze::trapeze(const point &a, const point &b, const point &c, const point &d) : a_{a}, b_{b}, c_{c}, d_{d} {}
trapeze::trapeze(std::istream &is) {
    is >> a_ >> b_ >> c_ >> d_;
}
double trapeze::area() const {
    if ( VectPropX(operator-(a_, b_), operator-(d_, c_)) == VectPropY(operator-(a_, b_), operator-(d_, c_)) || ( operator-(a_,b_).y == 0 && operator-(d_,c_).y == 0) ) {
        return ((VectNorm(a_, b_) + VectNorm(d_, c_)) / 2) * sqrt(
                VectNorm(d_, a_) * VectNorm(d_, a_) - (
                        pow((
                                    (pow((VectNorm(d_, c_) - VectNorm(a_, b_)), 2) +
                                     VectNorm(d_, a_) * VectNorm(d_, a_) - VectNorm(b_, c_) * VectNorm(b_, c_)) /
                                    (2 * (VectNorm(d_, c_) - VectNorm(a_, b_)))
                            ), 2)
                )
        );
    } else {
        std::cout << "It`s not a trapeze" << std::endl;
    }
}
point trapeze::center() const {
    return point {((a_.x + b_.x + c_.x + d_.x) / 4), ((a_.y + b_.y + c_.y + d_.y) / 4)};
}
std::ostream& trapeze::print(std::ostream &os) const {
    os << a_ << b_ << c_ << d_ << std::endl;
    return os;
}