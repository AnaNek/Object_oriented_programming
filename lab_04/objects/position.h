#ifndef POSITION_H
#define POSITION_H

#include <vector>
#include "point3d.h"

class Position
{
public:
    Position();
    std::vector<Point3D> getPos();
    void setPos(std::vector<Point3D>);
private:
    std::vector<Point3D> position;
};

#endif
