#ifndef BASE_LOADER_H
#define BASE_LOADER_H

#include "objects/model.h"
#include "modelBuilder.h"

class BaseLoader
{
public:
    BaseLoader() = default;
    virtual ~BaseLoader() = default;

    virtual Model* openModel(BaseBuilder&) = 0;
    virtual void saveModel(Model) = 0;
};

#endif
