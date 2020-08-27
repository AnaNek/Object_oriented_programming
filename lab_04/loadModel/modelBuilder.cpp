#include "modelBuilder.h"

ModelBuilder::ModelBuilder()
{
    this->model = new Model();
    this->built = false;
}

void ModelBuilder::buildEdges(int i, int j)
{
    Edge edge = Edge(i, j);
    model->addEdge(edge);
}

void ModelBuilder::buildVertice(double x, double y, double z)
{
    Point3D vert = Point3D(x, y, z);
    model->addPoint(vert);
}

void ModelBuilder::buildModel()
{
    this->built = true;
}

Model* ModelBuilder::getModel()
{
    if (this->built)
    {
        return this->model;
    }
    else
    {
        return nullptr;
    }
}

ModelBuilder::~ModelBuilder()
{

}
