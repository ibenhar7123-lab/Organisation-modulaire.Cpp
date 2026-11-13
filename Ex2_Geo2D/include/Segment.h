#ifndef SEGMENT_H
#define SEGMENT_H

#include "Point.h"

class Segment {
private:
    Point a, b;
public:
    Segment();
    Segment(const Point& a, const Point& b);
    double longueur() const;
};

#endif
