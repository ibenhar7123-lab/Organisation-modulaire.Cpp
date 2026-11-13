#ifndef POINT3D_H
#define POINT3D_H

class Point3D {
private:
    double x, y, z;

public:
    Point3D();                          // constructeur par défaut (0,0,0)
    Point3D(double x, double y, double z);

    double getX() const;
    double getY() const;
    double getZ() const;
};

#endif // POINT3D_H
