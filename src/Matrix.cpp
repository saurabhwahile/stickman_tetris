#include<iostream>

#include "Matrix.h"

using namespace std;

Matrix::Matrix()
{
    n=0;
}

void Matrix::Display()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<" "<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}
