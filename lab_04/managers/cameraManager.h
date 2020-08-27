#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include "baseManager.h"
#include "objects/camera.h"
#include "iterators/iterators.h"

class CameraManager : public BaseManager
{
public:
    CameraManager() = default;
    ~CameraManager() = default;

    void rotateX(double, ObjIt&);
    void rotateY(double, ObjIt&);
    void rotateZ(double, ObjIt&);
};

#endif
