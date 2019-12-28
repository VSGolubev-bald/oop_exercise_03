#include "rhombus.h"
#include <cmath>
rhombus::rhombus() : a_{0, 0}, b_{0, 0}, c_{0, 0}, d_{0, 0} {}
rhombus::rhombus(const point &a, const point &b, const point &c, const point &d) : a_(a), b_(b), c_(c), d_(d) {};
rhombus::rhombus(std::istream &is) {
    is >> a_ >> b_ >> c_ >> d_;
    if ( VectProd(operator-(a_, b_), operator-(d_, c_)) == 0  &&
         VectProd(operator-(a_, d_), operator-(b_, c_)) == 0 &&
         ScalProd(operator-(c_,a_), operator-(d_,b_)) == 0 ) {
        std::cout << "Correct" << std::endl;

    }
    else {
        std::cout << "Wrong" << std::endl;
        throw 1;


    }
}
double rhombus::area() const {
    return VectNorm(c_, a_) * VectNorm(d_, b_) / 2;
}

point rhombus::center() const {
    return point{((a_.x + b_.x + c_.x + d_.x) / 4), ((a_.y + b_.y + c_.y + d_.y) / 4)};
}

std::ostream &rhombus::print(std::ostream &os) const {
    os << a_ << b_ << c_ << d_ << std::endl;
    return os;
}



