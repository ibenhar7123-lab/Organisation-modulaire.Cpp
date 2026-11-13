#include "Segment.h"
#include <cmath>

Segment::Segment() : a(), b() {}
Segment::Segment(const Point& a, const Point& b) : a(a), b(b) {}

double Segment::longueur() const {
    double dx = b.getX() - a.getX();
    double dy = b.getY() - a.getY();
    return std::sqrt(dx * dx + dy * dy);
}
