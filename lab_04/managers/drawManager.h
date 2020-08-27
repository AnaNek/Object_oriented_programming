#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H

#include "baseManager.h"
#include "drawer/baseDrawer.h"
#include "objects/model.h"
#include "objects/position.h"
#include "iterators/iterators.h"
#include "exceptions/objectexception.h"
#include "exceptions/drawerexception.h"

class DrawManager : public BaseManager
{
public:
    DrawManager() = default;
    ~DrawManager() = default;

    void drawObjects(BaseDrawer &drawer, ObjIt &itBegin, ObjIt &itEnd);
};

#endif
