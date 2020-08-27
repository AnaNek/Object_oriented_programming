#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <fstream>
#include "errors.h"
#include "repository.h"
#include "mathlib.h"
#include "file.h"

struct Edge
{
    int first_index;
    int second_index;
};

struct Vertice
{
    double x;
    double y;
    double z;
};

struct Model
{
    bool load;

    Edge *edges;
    int numberEdges;

    Vertice *vertices;
    int numberVertices;
};

Model initModel();
error_t allocateModel(Model &model, int numberEdges, int numberVerteces);
void freeModel(Model &model);

#endif
