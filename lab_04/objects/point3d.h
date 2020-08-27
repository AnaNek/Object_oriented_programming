#ifndef POINT3D_H
#define POINT3D_H

//#include "matrix.h"
//#include "vector3d.h"

#include <cmath>
#include "point2d.h"

class Point3D
{
public:
    Point3D(): x0(0), y0(0), z0(0) {}
    Point3D(double x, double y, double z) : x0(x), y0(y), z0(z) {}

    Point3D(const Point3D &p);
    Point3D &operator=(const Point3D &p);
    Point3D &operator=(Point3D&& p);

    double x() const {return x0;}
    double y() const {return y0;}
    double z() const {return z0;}

    void setX(double x) {this->x0 = x;}
    void setY(double y) {this->y0 = y;}
    void setZ(double z) {this->z0 = z;}

    void move(double, double, double);
    void scale(double, double, double);
    void rotate(double, double, double);

    Point2D toPoint2D();

private:
    double x0;
    double y0;
    double z0;
};

#endif
