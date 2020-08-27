#ifndef BASE_DRAWER_H
#define BASE_DRAWER_H

#include "objects/point3d.h"
#include "objects/camera.h"

class BaseDrawer
{
public:
    BaseDrawer() = default;
    ~BaseDrawer() = default;
    virtual void drawLine(Point2D &p1, Point2D &p2) = 0;
    virtual void setCamera(Camera* camera) = 0;
};

#endif
