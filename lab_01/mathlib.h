#ifndef MATH_H
#define MATH_H

#include <cmath>
#include "repository.h"

typedef double matrix[4][4];
typedef double vector_col[4][1];
typedef double vector_row[1][4];

void createProjectMatr(matrix matr, double znear, double zfar, double aspect, double alpha);
void createScaleMatr(matrix res, Scale scaling);
void createMoveMatr(matrix res, Moving move);
void createRotMatr(matrix res, Rotate rotation);
void multVectMatr(vector_row res, vector_row vect, matrix matr);
void multMatrixs(matrix res, matrix first, matrix second);

#endif
