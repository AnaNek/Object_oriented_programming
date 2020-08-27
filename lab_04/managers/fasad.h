#ifndef FASAD_H
#define FASAD_H

#include "transform/transform.h"
#include "cameraManager.h"
#include "drawManager.h"
#include "fileManager.h"
#include "transformManager.h"
#include "scene.h"
#include "baseManager.h"

class Fasad
{
public:
    Fasad() = default;
    ~Fasad() = default;

    void requestTransform(BaseTransform&);
    void requestOpenModel(BaseLoader&, ModelBuilder&);
    void requestSaveModel(BaseLoader&);
    void requestDraw(BaseDrawer&);
    void requestAddCamera(Camera*);

private:
    Scene scene;
    TransformManager transformManager;
    FileManager fileManager;
    CameraManager cameraManager;
    DrawManager drawManager;
};

#endif
