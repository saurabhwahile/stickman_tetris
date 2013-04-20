#include <iostream>
#include <math.h>

#include "Transforms.h"

using namespace std;

Matrix Transforms::multiplyMatrix(Matrix A, Matrix B,int n)
{
    Matrix Solution;
    Solution.n=n;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<n; j++)
        {
            Solution.matrix[i][j] = 0;
            for(int k=0; k<3; k++)
            {
                Solution.matrix[i][j] = Solution.matrix[i][j] + A.matrix[i][k] * B.matrix[k][j] ;
            }
        }
    }

    //Solution.Display();

    return Solution;
}

Matrix Transforms::Translate(int tx, int ty,Matrix FigureMatrix,int n)
{
    Matrix TranslationMatrix;
    TranslationMatrix.n=3;
    TranslationMatrix.matrix[0][0]=1;TranslationMatrix.matrix[0][1]=0;TranslationMatrix.matrix[0][2]=tx;
    TranslationMatrix.matrix[1][0]=0;TranslationMatrix.matrix[1][1]=1;TranslationMatrix.matrix[1][2]=ty;
    TranslationMatrix.matrix[2][0]=0;TranslationMatrix.matrix[2][1]=0;TranslationMatrix.matrix[2][2]=1;

    FigureMatrix=multiplyMatrix(TranslationMatrix,FigureMatrix,n);
    //FigureMatrix.Display();

    return FigureMatrix;
}

Matrix Transforms::Reflection(int aboutx, int abouty,Matrix FigureMatrix,int n)
{
    if(aboutx==1&&abouty==0)
    {
        aboutx=1;
        abouty=-1;
    }
    else
    if(aboutx==0&&abouty==1)
    {
        aboutx=-1;
        abouty=1;
    }
    Matrix ReflectionMatrix;
    ReflectionMatrix.n=3;
    ReflectionMatrix.matrix[0][0]=aboutx;ReflectionMatrix.matrix[0][1]=0;ReflectionMatrix.matrix[0][2]=0;
    ReflectionMatrix.matrix[1][0]=0;ReflectionMatrix.matrix[1][1]=abouty;ReflectionMatrix.matrix[1][2]=0;
    ReflectionMatrix.matrix[2][0]=0;ReflectionMatrix.matrix[2][1]=0;ReflectionMatrix.matrix[2][2]=1;

    FigureMatrix=multiplyMatrix(ReflectionMatrix,FigureMatrix,n);
    //FigureMatrix.Display();

    return FigureMatrix;
}

Matrix Transforms::Scale(int sx, int sy,Matrix FigureMatrix,int n)
{
    Matrix ScaleMatrix;
    ScaleMatrix.n=3;
    ScaleMatrix.matrix[0][0]=sx;ScaleMatrix.matrix[0][1]=0;ScaleMatrix.matrix[0][2]=0;
    ScaleMatrix.matrix[1][0]=0;ScaleMatrix.matrix[1][1]=sy;ScaleMatrix.matrix[1][2]=0;
    ScaleMatrix.matrix[2][0]=0;ScaleMatrix.matrix[2][1]=0;ScaleMatrix.matrix[2][2]=1;
    int tx=FigureMatrix.matrix[0][0];
    int ty=FigureMatrix.matrix[1][0];

    FigureMatrix=Translate(-tx,-ty,FigureMatrix,n);
    FigureMatrix=multiplyMatrix(ScaleMatrix,FigureMatrix,n);
    FigureMatrix=Translate(tx,ty,FigureMatrix,n);
    //FigureMatrix.Display();

    return FigureMatrix;
}


Matrix Transforms::Rotate(float angle,Matrix FigureMatrix,int n)
{
    Matrix RotatationMatrix;
    angle=3.14*(angle/180);
    float sine,cosine;
    sine=sin(angle);
    cosine=cos(angle);
    int tx=FigureMatrix.matrix[0][0];
    int ty=FigureMatrix.matrix[1][0];
    RotatationMatrix.n=3;
    //RotatationMatrix.matrix= {{cosine,-sine,0},{sine,cosine,0},{0,0,1}};
    RotatationMatrix.matrix[0][0]=cosine;RotatationMatrix.matrix[0][1]=-sine;RotatationMatrix.matrix[0][2]=0;
    RotatationMatrix.matrix[1][0]=sine;RotatationMatrix.matrix[1][1]=cosine;RotatationMatrix.matrix[1][2]=0;
    RotatationMatrix.matrix[2][0]=0;RotatationMatrix.matrix[2][1]=0;RotatationMatrix.matrix[2][2]=1;

    FigureMatrix=Translate(-tx,-ty,FigureMatrix,n);
    FigureMatrix=multiplyMatrix(RotatationMatrix,FigureMatrix,n);
    FigureMatrix=Translate(tx,ty,FigureMatrix,n);
    //cout<<"\n";
    //FigureMatrix.Display();

    return FigureMatrix;
}

