#ifndef DRAWER_H
#define DRAWER_H

#include "baseDrawer.h"
#include <QGraphicsScene>

class Drawer : public BaseDrawer
{
public:
    Drawer(QGraphicsScene*);

    void drawLine(Point2D &p1, Point2D &p2) override;
    void setCamera(Camera *camera) override;
private:
    QGraphicsScene *scene;
    Camera *camera;
};

#endif
