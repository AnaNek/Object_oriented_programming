#ifndef BASE_BUILDER_H
#define BASE_BUILDER_H

#include "objects/model.h"

class BaseBuilder
{
public:
    BaseBuilder() = default;
    virtual ~BaseBuilder() = default;

    virtual void buildVertice(double, double, double) = 0;
    virtual void buildEdges(int, int) = 0;
    virtual void buildModel() = 0;
    virtual Model* getModel() = 0;
};

#endif
