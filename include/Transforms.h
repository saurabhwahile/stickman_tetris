#ifndef TRANSFORMS_H
#define TRANSFORMS_H

#include "Matrix.h"
class Transforms
{
public:
    Matrix multiplyMatrix(Matrix A, Matrix B,int n);
public:
    Matrix Translate(int tx, int ty,Matrix FigureMatrix,int n);
public:
    Matrix Scale(int sx, int sy,Matrix FigureMatrix,int n);
public:
    Matrix Rotate(float angle,Matrix FigureMatrix,int n);
public:
    Matrix Reflection(int aboutx, int abouty,Matrix FigureMatrix,int n);
};

#endif // TRANSFORMS_H
