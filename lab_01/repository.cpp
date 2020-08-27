#include "repository.h"

void setMoving(Moving &data, double dx, double dy, double dz)
{
    data.dx = dx;
    data.dy = dy;
    data.dz = dz;
}

void setRotate(Rotate &data, double ox, double oy, double oz)
{
    data.ox = ox;
    data.oy = oy;
    data.oz = oz;
}

void setScale(Scale &data, double kx, double ky, double kz)
{
    data.kx = kx;
    data.ky = ky;
    data.kz = kz;
}

void setPoint(Point &p, coord_t x, coord_t y)
{
    p.x = x;
    p.y = y;
}

struct Scale get_scale(Repository &data)
{
    return data.scaling;
}

struct Rotate get_rotate(Repository &data)
{
    return data.rotation;
}

struct Moving get_moving(Repository &data)
{
    return data.move;
}

void createRepository(Repository &repository)
{

    setMoving(repository.move, 0, 0, 0);
    setRotate(repository.rotation, 0, 0, 0);
    setScale(repository.scaling, 1, 1, 1);

    repository.points = nullptr;
    repository.numberPoints = 0;

    repository.ind = nullptr;
    repository.numberInd = 0;

    repository.file = nullptr;
}

error_t allocateProjections(Point **points, int &numberPoints)
{
    error_t er = SUCCESS;

    if (points == nullptr)
    {
        er = MEM_ERR_POINT;
        return er;
    }

    if (numberPoints <= 0)
    {
        er = MEM_ERR_POINT;
        return er;
    }

    if (!*points)
    {
        *points = new Point[numberPoints];
    }
    else
    {
        delete[] *points;
        *points = new Point[numberPoints];
    }

    if (*points == nullptr)
    {
        er = MEM_ERR_POINT;
    }

    return er;
}

error_t allocateIndexs(Indexes **ind, int &numberInd)
{
    error_t er = SUCCESS;

    if (ind == nullptr)
    {
        er = MEM_ERR_INDEX;
        return er;
    }

    if (numberInd <= 0)
    {
        er = MEM_ERR_INDEX;
        return er;
    }

    if (!*ind)
    {
        *ind = new Indexes[numberInd];
    }
    else
    {
        delete[] *ind;
        *ind = new Indexes[numberInd];
    }

    if (*ind == nullptr)
    {
        er = MEM_ERR_INDEX;
    }

    return er;
}
