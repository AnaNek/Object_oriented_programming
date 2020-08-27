#include "transform_points.h"

void assignVertToMatrix(matrix matr, const Vertice &vert)
{
    matr[0][0] = vert.x;
    matr[0][1] = vert.y;
    matr[0][2] = vert.z;
}

error_t transformPoints(Point **points, int &numberPoints, Indexes **ind, int &numberInd, Model &model)
{
    error_t er = SUCCESS;

    if (model.load == false)
    {
        er = NOT_LOADED;
        return er;
    }

    numberInd = model.numberEdges;
    numberPoints = model.numberVertices;

    matrix ProjMatr;
    createProjectMatr(ProjMatr, 0.001, 1000.0, 1.0, 60.0);

    er = allocateProjections(points, numberPoints);

    if (er == MEM_ERR)
    {
        return er;
    }

    vector_row coords;

    for (int i = 0; i < numberPoints; i++)
    {
        assignVertToMatrix(coords, model.vertices[i]);
        coords[0][2] -= 2;
        coords[0][3] = 1;

        vector_row res;
        multVectMatr(res, coords, ProjMatr);

        coord_t x = res[0][0] / coords[0][2];
        coord_t y = res[0][1] / coords[0][2];

        setPoint((*points)[i], x, y);
    }

    er = allocateIndexs(ind, numberInd);

    if (er == MEM_ERR)
    {
        return er;
    }

    Indexes *indexes = *ind;
    for (int i = 0; i < numberInd; i++)
    {
        Edge curEdg = model.edges[i];

        indexes[i].first_index = curEdg.first_index;
        indexes[i].second_index = curEdg.second_index;
    }

    return er;
}
