#ifndef MODEL_BUILDER_H
#define MODEL_BUILDER_H

#include "baseBuilder.h"

class ModelBuilder : public BaseBuilder
{
public:
    ModelBuilder();
    ~ModelBuilder() override;

    void buildVertice(double, double, double) override;
    void buildEdges(int, int) override;
    void buildModel() override;
    Model* getModel() override;

private:
    Model *model;
    bool built;
};

#endif
