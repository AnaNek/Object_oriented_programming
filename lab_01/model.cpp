#include "model.h"

Model initModel()
{
    Model model;

    model.load = false;
    model.numberEdges = 0;
    model.numberVertices = 0;
    model.vertices = nullptr;
    model.edges = nullptr;

    return model;
}

error_t allocateModel(Model &model, int numberEdges, int numberVerteces)
{
    error_t er = SUCCESS;

    model.edges = new Edge[numberEdges];
    model.vertices = new Vertice[numberVerteces];

    if (model.edges == nullptr || model.vertices == nullptr)
    {
        er = MEM_ERR;
    }
    return er;
}

void freeModel(Model &model)
{
    delete[] model.edges;
    delete[] model.vertices;
}
