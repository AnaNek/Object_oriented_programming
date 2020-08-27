#include "operations_model.h"

void assignVertToMatr(vector_row matr, const Vertice &vert)
{
    matr[0][0] = vert.x;
    matr[0][1] = vert.y;
    matr[0][2] = vert.z;
}

void assignMatrToVert(Vertice &vert, const vector_row matr)
{
    vert.x = matr[0][0];
    vert.y = matr[0][1];
    vert.z = matr[0][2];
}

error_t scaleModel(Model &model, Repository &repository)
{
    error_t er = SUCCESS;

    if (model.load == false)
    {
        er = NOT_LOADED;
        return er;
    }

    matrix ScaleMatr;
    createScaleMatr(ScaleMatr, repository.scaling);

    vector_row coords;

    for (int i = 0; i < model.numberVertices; i++)
    {
        assignVertToMatr(coords, model.vertices[i]);
        coords[0][3] = 1;

        vector_row res;
        multVectMatr(res, coords, ScaleMatr);

        assignMatrToVert(model.vertices[i], res);
    }
    return er;
}

error_t moveModel(Model &model, Repository &repository)
{
    error_t er = SUCCESS;

    if (model.load == false)
    {
        er = NOT_LOADED;
        return er;
    }

    matrix MoveMatr;
    createMoveMatr(MoveMatr, repository.move);

    vector_row coords;

    for (int i = 0; i < model.numberVertices; i++)
    {
        assignVertToMatr(coords, model.vertices[i]);
        coords[0][3] = 1;

        vector_row res;
        multVectMatr(res, coords, MoveMatr);

        assignMatrToVert(model.vertices[i], res);
    }
    return er;
}

error_t rotateModel(Model &model, Repository &repository)
{
    error_t er = SUCCESS;

    if (model.load == false)
    {
        er = NOT_LOADED;
        return er;
    }

    matrix RotMatr;
    createRotMatr(RotMatr, repository.rotation);

    vector_row coords;

    for (int i = 0; i < model.numberVertices; i++)
    {
        assignVertToMatr(coords, model.vertices[i]);
        coords[0][3] = 1;

        vector_row res;
        multVectMatr(res, coords, RotMatr);

        assignMatrToVert(model.vertices[i], res);
    }
    return er;
}
