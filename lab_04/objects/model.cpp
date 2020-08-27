#include "model.h"

Model::Model(const Model& model)
{
    this->verticies = model.verticies;
    this->edges = model.edges;
}

Model::Model(Model&& model)
{
    this->verticies = model.verticies;
    this->edges = model.edges;
}

Model& Model::operator=(const Model& model)
{
    this->verticies = model.verticies;
    this->edges = model.edges;
    return *this;
}

Model& Model::operator=(Model&& model)
{
    this->verticies = model.verticies;
    this->edges = model.edges;
    return *this;
}
