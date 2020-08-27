#ifndef TRANSFORM_MANAGER_H
#define TRANSFORM_MANAGER_H

#include "baseManager.h"
#include "iterators/iterators.h"
#include "objects/object.h"
#include "transform/transform.h"
#include "exceptions/objectexception.h"

class TransformManager : public BaseManager
{
public:
    TransformManager() = default;
    ~TransformManager() = default;

    void transformModel(BaseTransform&, ObjIt &itBegin, ObjIt &itEnd);
};

#endif
