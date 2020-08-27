#include "fasad.h"

void Fasad::requestDraw(BaseDrawer &d)
{
    ObjIt begin = this->scene.objectBegin();
    ObjIt end = this->scene.objectEnd();
    this->drawManager.drawObjects(d, begin, end);
}

void Fasad::requestOpenModel(BaseLoader &loader, ModelBuilder &builder)
{
    Model *model = this->fileManager.openModel(loader, builder);
    this->scene.addObject(model);
}

void Fasad::requestSaveModel(BaseLoader &loader)
{
    ObjIt begin = this->scene.objectBegin();
    ObjIt end = this->scene.objectEnd();
    this->fileManager.saveModel(loader, begin, end);
}

void Fasad::requestAddCamera(Camera *c)
{
    this->scene.addCamera(c);
}

void Fasad::requestTransform(BaseTransform& trans)
{
    ObjIt begin = this->scene.objectBegin();
    ObjIt end = this->scene.objectEnd();
    this->transformManager.transformModel(trans, begin, end);
}
