#include "pentagon.h"
#define PI 3.14159265
pentagon::pentagon() : a_{0, 0}, b_{0, 0}, c_{0, 0}, d_{0, 0}, e_{0, 0} {}
pentagon::pentagon(const point &a, const point &b, const point &c, const point &d, const point &e) : a_(a), b_(b), c_(c), d_(d), e_(e) {}
pentagon::pentagon(std::istream &is) {
    is >> a_ >> b_ >> c_ >> d_>> e_;
}
point pentagon::center() const {
    return point {((a_.x + b_.x + c_.x + d_.x + e_.x) / 5), ((a_.y + b_.y + c_.y + d_.y + e_.y) / 5) } ;
}
double pentagon::area() const {
        return TrAngle(a_,b_,c_) + TrAngle(c_,d_,e_) + TrAngle(a_,c_,e_);
}
std::ostream& pentagon::print(std::ostream &os) const {
    os << a_ << b_ << c_ << d_ << e_;
}