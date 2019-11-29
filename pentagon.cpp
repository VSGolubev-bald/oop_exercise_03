#include "pentagon.h"
pentagon::pentagon() : a_{0, 0}, b_{0, 0}, c_{0, 0}, d_{0, 0}, e_{0, 0} {}
pentagon::pentagon(const point &a, const point &b, const point &c, const point &d, const point &e) : a_(a), b_(b), c_(c), d_(d), e_(e) {}
pentagon::pentagon(std::istream &is) {
    is >> a_ >> b_ >> c_ >> d_>> e_;
}
point pentagon::center() const {
    return point {((a_.x + b_.x + c_.x + d_.x + e_.x) / 4), ((a_.y + b_.y + c_.y + d_.y + e_.y) / 4) } ;
}
double pentagon::area() const {
    return TrArea(a_,b_,c_) + TrArea(a_,c_,e_) + TrArea(c_,e_,d_);
}
std::ostream& pentagon::print(std::ostream &os) const {
    os << a_ << b_ << c_ << d_ << e_;
}