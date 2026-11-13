#include "Triangle.h"
#include "Segment.h"

Triangle::Triangle() : a(), b(), c() {}
Triangle::Triangle(const Point& a, const Point& b, const Point& c) : a(a), b(b), c(c) {}

double Triangle::perimetre() const {
    return Segment(a, b).longueur() + Segment(b, c).longueur() + Segment(c, a).longueur();
}
