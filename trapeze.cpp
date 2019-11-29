#include "trapeze.h"
#include <cmath>

trapeze::trapeze(): a_{0, 0}, b_{0, 0}, c_{0, 0}, d_{0, 0} {}
trapeze::trapeze(const point &a, const point &b, const point &c, const point &d) : a_{a}, b_{b}, c_{c}, d_{d} {}
trapeze::trapeze(std::istream &is) {
    is >> a_ >> b_ >> c_ >> d_;
}
double trapeze::area() const {
    if ( VectPropX(operator-(b_, a_), operator-(d_, c_)) == VectPropY (operator-(b_, a_), operator-(d_, c_)) ) {
        return (VectNorm(b_, a_) + VectNorm(d_,c_) / 2) * sqrt ( pow(VectNorm(c_, a_) , 2)
        -  pow ( ( (pow((VectNorm(d_,c_) - VectNorm(b_, a_)), 2) + pow(VectNorm(c_, a_), 2) - pow(VectNorm(d_, b_), 2) ) /
                (2 * (VectNorm(d_,c_) - VectNorm(b_, a_))) ) , 2) );
    } else {
        std::cout << "This is not a trapeze" << std::endl;
    }
}
point trapeze::center() const {
    return point {((a_.x + b_.x + c_.x + d_.x) / 4), ((a_.y + b_.y + c_.y + d_.y) / 4)};
}
std::ostream& trapeze::print(std::ostream &os) const {
    os << a_ << b_ << c_ << d_ << std::endl;
    return os;
}