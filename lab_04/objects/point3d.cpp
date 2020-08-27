#include "point3d.h"

Point3D::Point3D(const Point3D &obj)
{
    this->x0 = obj.x();
    this->y0 = obj.y();
    this->z0 = obj.z();
}

Point3D &Point3D::operator=(const Point3D &obj)
{
    this->x0 = obj.x();
    this->y0 = obj.y();
    this->z0 = obj.z();

    return (*this);
}

Point3D &Point3D::operator=(Point3D &&obj)
{
    *this = obj;
    return (*this);
}

void Point3D::move(double dx, double dy, double dz)
{
    this->x0 += dx;
    this->y0 += dy;
    this->z0 += dz;
}

void Point3D::scale(double kx, double ky, double kz)
{
    this->x0 *= kx;
    this->y0 *= ky;
    this->z0 *= kz;
}

void Point3D::rotate(double ox, double oy, double oz)
{
    double sup = this->y0;
    this->y0 = this->y0 * cos(ox) + this->z0 * sin(ox);
    this->z0 = -sup * sin(ox) + this->z0 * cos(ox);

    sup = this->z0;
    this->z0 = this->z0 * cos(oy) + this->x0 * sin(oy);
    this->x0 = -sup * sin(oy) + this->x0 * cos(oy);

    sup = this->x0;
    this->x0 = this->x0 * cos(oz) + this->y0 * sin(oz);
    this->y0 = -sup * sin(oz) + this->y0 * cos(oz);
}

Point2D Point3D::toPoint2D()
{
    double x = this->x0 + this->z0 * 0.5;
    double y = -this->y0 - this->z0 * 0.5;
    Point2D point = Point2D(x, y);
    return point;
}
