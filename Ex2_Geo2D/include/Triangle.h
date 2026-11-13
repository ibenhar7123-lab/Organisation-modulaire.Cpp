#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle {
private:
    Point a, b, c;
public:
    Triangle();
    Triangle(const Point& a, const Point& b, const Point& c);
    double perimetre() const;
};

#endif
