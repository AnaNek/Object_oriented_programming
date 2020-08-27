#ifndef CAMERA_H
#define CAMERA_H

#include "object.h"
#include "point3d.h"
//#include "matrix.h"

class Camera : public InvisibleObject
{
public:
    Camera(const Point3D &view): view(view) {}
    Camera(const Point3D &pos, const Point3D &view): view(view), position(pos) {}
    Camera(const Camera &cam);

    Point3D getView() const {return view;}
    void setView(const Point3D &v) {view = v;}

    Point3D getPos() const {return position;}
    void setPos(const Point3D &p) {position = p;}

protected:
    Point3D view;
    Point3D position;
};

#endif
