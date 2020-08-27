#include "position.h"

std::vector<Point3D> Position::getPos()
{
    return this->position;
}

void Position::setPos(std::vector<Point3D> p)
{
    position = p;
}
