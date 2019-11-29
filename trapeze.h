#include "figure.h"
#ifndef LAB3_TRAPEZE_H
#define LAB3_TRAPEZE_H
class trapeze : public figure {
public:
    trapeze();
    trapeze(const point& a, const point& b, const point& c, const point& d);
    trapeze(std::istream& is);
    double area() const override;
    point center() const override;
    std::ostream& print(std::ostream& os) const override;
private:
    point a_;
    point b_;
    point c_;
    point d_;
};
#endif //LAB3_TRAPEZE_H
