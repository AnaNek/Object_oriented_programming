#include "transformManager.h"

void TransformManager::transformModel(BaseTransform &trans, ObjIt &itBegin, ObjIt &itEnd)
{
    for (ObjIt it = itBegin; it != itEnd; it++)
    {
        if (!(*it))
        {
            throw ObjectOutOfRangeException();
        }

        trans.transform(*it);
    }
}
