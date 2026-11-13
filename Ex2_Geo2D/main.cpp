#include <iostream>
#include "Point.h"
#include "Segment.h"
#include "Triangle.h"
using namespace std;

int main() {
    Point A(0, 0), B(4, 0), C(0, 3);

    Segment s(A, B);
    cout << "Longueur de AB = " << s.longueur() << endl;

    Triangle t(A, B, C);
    cout << "Perimetre du triangle ABC = " << t.perimetre() << endl;   // 3 + 4 + 5 = 12
    return 0;
}
