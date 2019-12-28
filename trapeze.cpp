#include "trapeze.h"
#include <cmath>

trapeze::trapeze(): a_{0, 0}, b_{0, 0}, c_{0, 0}, d_{0, 0} {}
trapeze::trapeze(const point &a, const point &b, const point &c, const point &d) : a_{a}, b_{b}, c_{c}, d_{d} {}
trapeze::trapeze(std::istream &is) {
    is >> a_ >> b_ >> c_ >> d_;
    if ( ( VectProd(operator-(a_,b_), operator-(d_,c_)) == 0) ||
         (VectProd(operator-(b_,c_), operator-(a_,d_)) == 0)  ) {
        std::cout << "Correct" << std::endl;
    } else {
        std::cout << "Wrong" << std::endl;
    }
}
double trapeze::area() const {
    if (VectProd(operator-(a_,b_), operator-(d_,c_)) == 0) {
        return ((VectNorm(a_, b_) + VectNorm(d_, c_)) / 2) * sqrt(
                VectNorm(d_, a_) * VectNorm(d_, a_) - (
                        pow((
                                    (pow((VectNorm(d_, c_) - VectNorm(a_, b_)), 2) +
                                     VectNorm(d_, a_) * VectNorm(d_, a_) - VectNorm(b_, c_) * VectNorm(b_, c_)) /
                                    (2 * (VectNorm(d_, c_) - VectNorm(a_, b_)))
                            ), 2)
                )
        );

    } else if (VectProd(operator-(b_,c_), operator-(a_,d_)) == 0) {
        return ((VectNorm(b_, c_) + VectNorm(a_, d_)) / 2) * sqrt(
                VectNorm(a_, b_) * VectNorm(a_, b_) - (
                        pow((
                                    (pow((VectNorm(a_, d_) - VectNorm(b_, c_)), 2) +
                                     VectNorm(a_, b_) * VectNorm(a_, b_) - VectNorm(c_, d_) * VectNorm(c_, d_)) /
                                    (2 * (VectNorm(a_, d_) - VectNorm(b_, c_)))
                            ), 2)
                )
        );
    }
}

point trapeze::center() const {
    return point{((a_.x + b_.x + c_.x + d_.x) / 4), ((a_.y + b_.y + c_.y + d_.y) / 4)};
}

std::ostream &trapeze::print(std::ostream &os) const {
    os << a_ << b_ << c_ << d_ << std::endl;
    return os;
}