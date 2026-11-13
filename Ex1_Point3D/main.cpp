#include <iostream>
#include "Point3D.h"
using namespace std;

int main() {
    Point3D p1;                    // (0,0,0)
    Point3D p2(1.5, -2.0, 3.25);

    cout << "p1 = (" << p1.getX() << ", " << p1.getY() << ", " << p1.getZ() << ")" << endl;
    cout << "p2 = (" << p2.getX() << ", " << p2.getY() << ", " << p2.getZ() << ")" << endl;
    return 0;
}
