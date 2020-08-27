#include "mathlib.h"

void fillMatr(matrix matr, int row, int col, double value)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                matr[i][j] = value;
            }
            else
            {
                matr[i][j] = 0;
            }
        }
    }
}

void createProjectMatr(matrix matr, double znear, double zfar, double aspect, double alpha)
{
    double zrange = znear - zfar;
    double tan_half_alf = tan((M_PI * alpha * 0.5) / 180.0);

    matr[0][0] = ((double)1) / (tan_half_alf * aspect);
    matr[0][1] = 0;
    matr[0][2] = 0;
    matr[0][3] = 0;

    matr[1][0] = 0;
    matr[1][1] = ((double)1) / tan_half_alf;
    matr[1][2] = 0;
    matr[1][3] = 0;

    matr[2][0] = 0;
    matr[2][1] = 0;
    matr[2][2] = (-znear - zfar) / zrange;
    matr[2][3] =  2 * zfar * znear / zrange;

    matr[3][0] = 0;
    matr[3][1] = 0;
    matr[3][2] = 1;
    matr[3][3] = 0;
}

void createScaleMatr(matrix res, Scale scaling)
{
    fillMatr(res, 4, 4, 1);

    res[0][0] = scaling.kx;
    res[1][1] = scaling.ky;
    res[2][2] = scaling.kz;
}

void createMoveMatr(matrix res, Moving move)
{
    fillMatr(res, 4, 4, 1);

    res[3][0] = move.dx;
    res[3][1] = move.dy;
    res[3][2] = move.dz;
}

void createMatrX(matrix res, double ox)
{
    fillMatr(res, 4, 4, 1);

    res[1][1] = cos(ox);
    res[1][2] = sin(ox);
    res[2][1] = -sin(ox);
    res[2][2] = cos(ox);
}

void createMatrY(matrix res, double oy)
{
    fillMatr(res, 4, 4, 1);

    res[0][0] = cos(oy);
    res[0][2] = -sin(oy);
    res[2][0] = sin(oy);
    res[2][2] = cos(oy);
}

void createMatrZ(matrix res, double oz)
{
    fillMatr(res, 4, 4, 1);

    res[0][0] = cos(oz);
    res[0][1] = sin(oz);
    res[1][0] = -sin(oz);
    res[1][1] = cos(oz);
}

void createRotMatr(matrix res, Rotate rotation)
{
    matrix matrX;
    createMatrX(matrX, rotation.ox);
    matrix matrY;
    createMatrY(matrY, rotation.oy);
    matrix matrZ;
    createMatrZ(matrZ, rotation.oz);

    matrix resXY;
    multMatrixs(resXY, matrX, matrY);
    multMatrixs(res, resXY, matrZ);
}

void  multVectMatr(vector_row res, vector_row vect, matrix matr)
{
    double sum = 0;

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sum = 0;
            for (int k = 0; k < 4; k++)
                sum += vect[i][k] * matr[k][j];
            res[i][j] = sum;
        }
    }
}

void  multMatrixs(matrix res, matrix first, matrix second)
{
    double sum = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sum = 0;
            for (int k = 0; k < 4; k++)
                sum += first[i][k] * second[k][j];
            res[i][j] = sum;
        }
    }
}
