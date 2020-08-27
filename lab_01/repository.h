#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "errors.h"

typedef int operation_t;
typedef double coord_t;

#define MOVING    1
#define ROTATE    2
#define SCALE     3
#define OPENNING  4
#define SAVING    5
#define TRANSFORM 6
#define EXIT      7

struct Point
{
    coord_t x;
    coord_t y;
};

struct Rotate
{
    double ox;
    double oy;
    double oz;
};

struct Scale
{
    double kx;
    double ky;
    double kz;
};

struct Moving
{
    double dx;
    double dy;
    double dz;
};

struct Indexes
{
    int first_index;
    int second_index;
};

struct Repository
{
    Rotate rotation;
    Scale scaling;
    Moving move;

    Point *points;
    int numberPoints;

    Indexes *ind;
    int numberInd;
    char *file;
};

void createRepository(Repository &repository);
void setScale(struct Scale &data, double kx, double ky, double kz);
void setRotate(struct Rotate &data, double ox, double oy, double oz);
void setMoving(struct Moving &data, double dx, double dy, double dz);
void setPoint(Point &p, coord_t x, coord_t y);
struct Scale getScale(struct Repository &data);
struct Rotate getRotate(struct Repository &data);
struct Moving getMoving(struct Repository &data);
error_t allocateProjections(Point **points, int &numberPoints);
error_t allocateIndexs(Indexes **ind, int &numberInd);

#endif
