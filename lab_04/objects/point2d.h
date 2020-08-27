#ifndef POINT2D_H
#define POINT2D_H

class Point2D
{
public:
    Point2D(): x0(0), y0(0) {}
    Point2D(double x, double y) : x0(x), y0(y) {}

    Point2D(const Point2D &p);
    Point2D &operator=(const Point2D &p);
    Point2D &operator=(Point2D&& p);

    double x() const {return x0;}
    double y() const {return y0;}

    void setX(double x) {this->x0 = x;}
    void setY(double y) {this->y0 = y;}

private:
    double x0;
    double y0;
};

#endif
