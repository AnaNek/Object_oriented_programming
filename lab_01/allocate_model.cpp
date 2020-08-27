#include "allocate_model.h"

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
