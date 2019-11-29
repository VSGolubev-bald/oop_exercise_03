
#include "point.h"
point operator+ (point l, point r) {
    return {l.x + r.x, l.y + r.y};
};
point operator- (point l, point r) {
    return { l.x - r.x, l.y - r.y};
};
point operator* (point p, double a) {
    return {p.x * a, p.y * a};
};
point operator/ (point p, double a) {
    return {p.x / a, p.y / a};
};
std::istream &operator>> (std::istream &is, point &p) {
    is >> p.x >> p.y;
    return is;
}
std::ostream &operator<< (std::ostream &os, const point &p) {
    os << p.x << " " << p.y << std::endl;
    return os;
}
