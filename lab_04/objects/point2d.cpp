#include "point2d.h"

Point2D::Point2D(const Point2D &obj)
{
    this->x0 = obj.x();
    this->y0 = obj.y();
}

Point2D &Point2D::operator=(const Point2D &obj)
{
    this->x0 = obj.x();
    this->y0 = obj.y();

    return (*this);
}
