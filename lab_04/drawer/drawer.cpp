#include "drawer.h"

Drawer::Drawer(QGraphicsScene *s)
{
    this->scene = s;
}

void Drawer::drawLine(Point2D &p1, Point2D &p2)
{
   this->scene->addLine(p1.x(), p1.y(), p2.x(), p2.y());
}

void Drawer::setCamera(Camera *camera)
{
    this->camera = camera;
}
