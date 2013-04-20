#include "Objects.h"
#include "Matrix.h"
#include "Transforms.h"

#include<graphics.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

Objects::Objects()
{
    frame=0;
    ObjectCount=0;
    for(int i=0; i<5; i++)
    {
        Object[i].n=8;
    }
    //Object 1
    Object[0].matrix[0][0]=0; Object[0].matrix[1][0]=0; Object[0].matrix[2][0]=1;
    Object[0].matrix[0][1]=16; Object[0].matrix[1][1]=0; Object[0].matrix[2][1]=1;
    Object[0].matrix[0][2]=32; Object[0].matrix[1][2]=0; Object[0].matrix[2][2]=1;
    Object[0].matrix[0][3]=32; Object[0].matrix[1][3]=16; Object[0].matrix[2][3]=1;
    Object[0].matrix[0][4]=32; Object[0].matrix[1][4]=32; Object[0].matrix[2][4]=1;
    Object[0].matrix[0][5]=16; Object[0].matrix[1][5]=32; Object[0].matrix[2][5]=1;
    Object[0].matrix[0][6]=0; Object[0].matrix[1][6]=32; Object[0].matrix[2][6]=1;
    Object[0].matrix[0][7]=0; Object[0].matrix[1][7]=16; Object[0].matrix[2][7]=1;
    //Object 2
    Object[1].matrix[0][0]=0; Object[1].matrix[1][0]=0; Object[1].matrix[2][0]=1;
    Object[1].matrix[0][1]=16; Object[1].matrix[1][1]=0; Object[1].matrix[2][1]=1;
    Object[1].matrix[0][2]=32; Object[1].matrix[1][2]=0; Object[1].matrix[2][2]=1;
    Object[1].matrix[0][3]=48; Object[1].matrix[1][3]=0; Object[1].matrix[2][3]=1;
    Object[1].matrix[0][4]=48; Object[1].matrix[1][4]=16; Object[1].matrix[2][4]=1;
    Object[1].matrix[0][5]=32; Object[1].matrix[1][5]=16; Object[1].matrix[2][5]=1;
    Object[1].matrix[0][6]=16; Object[1].matrix[1][6]=16; Object[1].matrix[2][6]=1;
    Object[1].matrix[0][7]=0; Object[1].matrix[1][7]=16; Object[1].matrix[2][7]=1;
    //Object 3
    Object[2].matrix[0][0]=0; Object[2].matrix[1][0]=0; Object[2].matrix[2][0]=1;
    Object[2].matrix[0][1]=16; Object[2].matrix[1][1]=0; Object[2].matrix[2][1]=1;
    Object[2].matrix[0][2]=16; Object[2].matrix[1][2]=16; Object[2].matrix[2][2]=1;
    Object[2].matrix[0][3]=32; Object[2].matrix[1][3]=16; Object[2].matrix[2][3]=1;
    Object[2].matrix[0][4]=32; Object[2].matrix[1][4]=48; Object[2].matrix[2][4]=1;
    Object[2].matrix[0][5]=16; Object[2].matrix[1][5]=48; Object[2].matrix[2][5]=1;
    Object[2].matrix[0][6]=16; Object[2].matrix[1][6]=32; Object[2].matrix[2][6]=1;
    Object[2].matrix[0][7]=0; Object[2].matrix[1][7]=32; Object[2].matrix[2][7]=1;
    //Object 4
    Object[3].matrix[0][0]=16; Object[3].matrix[1][0]=0; Object[3].matrix[2][0]=1;
    Object[3].matrix[0][1]=32; Object[3].matrix[1][1]=0; Object[3].matrix[2][1]=1;
    Object[3].matrix[0][2]=32; Object[3].matrix[1][2]=32; Object[3].matrix[2][2]=1;
    Object[3].matrix[0][3]=16; Object[3].matrix[1][3]=32; Object[3].matrix[2][3]=1;
    Object[3].matrix[0][4]=16; Object[3].matrix[1][4]=48; Object[3].matrix[2][4]=1;
    Object[3].matrix[0][5]=0; Object[3].matrix[1][5]=48; Object[3].matrix[2][5]=1;
    Object[3].matrix[0][6]=0; Object[3].matrix[1][6]=16; Object[3].matrix[2][6]=1;
    Object[3].matrix[0][7]=16; Object[3].matrix[1][7]=16; Object[3].matrix[2][7]=1;
    //Object 5
    Object[4].matrix[0][0]=16; Object[4].matrix[1][0]=0; Object[4].matrix[2][0]=1;
    Object[4].matrix[0][1]=32; Object[4].matrix[1][1]=0; Object[4].matrix[2][1]=1;
    Object[4].matrix[0][2]=32; Object[4].matrix[1][2]=16; Object[4].matrix[2][2]=1;
    Object[4].matrix[0][3]=48; Object[4].matrix[1][3]=16; Object[4].matrix[2][3]=1;
    Object[4].matrix[0][4]=48; Object[4].matrix[1][4]=32; Object[4].matrix[2][4]=1;
    Object[4].matrix[0][5]=0; Object[4].matrix[1][5]=32; Object[4].matrix[2][5]=1;
    Object[4].matrix[0][6]=0; Object[4].matrix[1][6]=16; Object[4].matrix[2][6]=1;
    Object[4].matrix[0][7]=16; Object[4].matrix[1][7]=16; Object[4].matrix[2][7]=1;

}

void Objects::draw(int n)
{
    Object[n].n=8;
    for(int i=0; i<Object[n].n-1; i++)
    {
        line(Object[n].matrix[0][i],Object[n].matrix[1][i],Object[n].matrix[0][i+1],Object[n].matrix[1][i+1]);
    }
    line(Object[n].matrix[0][Object[n].n-1],Object[n].matrix[1][Object[n].n-1],Object[n].matrix[0][0],Object[n].matrix[1][0]);
}

void Objects::draw(Matrix Object)
{
    Object.n=8;
    for(int i=0; i<Object.n-1; i++)
    {
        line(Object.matrix[0][i],Object.matrix[1][i],Object.matrix[0][i+1],Object.matrix[1][i+1]);
    }
    line(Object.matrix[0][Object.n-1],Object.matrix[1][Object.n-1],Object.matrix[0][0],Object.matrix[1][0]);
}

Matrix Objects::decideInitialPosition(Matrix Object)
{
    Transforms T;
    //srand(time(NULL));
    int randomNumber=rand()%39+0;
    //cout<<"\ndecideInitialPosition="<<randomNumber;
    randomNumber=randomNumber*16;
    Object.n=8;
    Object=T.Translate(-Object.matrix[0][0],-Object.matrix[1][0],Object,Object.n);
    Object=T.Translate(randomNumber,0,Object,Object.n);
    //Rotatation?
    /*
    randomNumber=rand()%4+0;
    cout<<"\nAngle="<<randomNumber;
    Object=T.Rotate(randomNumber*90,Object,Object.n);
    */
    return Object;
}

void Objects::decideObject()
{
    //srand(time(NULL));
    int randomNumber=rand()%5+0;
    //cout<<"\ndecideObject="<<randomNumber;
    ObjectCache[ObjectCount]=decideInitialPosition(Object[randomNumber]);
    ObjectCacheType[ObjectCount]=randomNumber;
    ObjectTranslateFlag[ObjectCount]=true;
    ObjectCount++;
}

void Objects::checkObstacle(Matrix Object, int ObjectNumber)
{
    if(ObjectTranslateFlag[ObjectNumber]==false)
    {
        return;
    }
    Object.n=8;
    bool BreakFlag=false;

    bool CheckFlag=false;

    for(int i=0; i<ObjectCount; i++)
    {
        CheckFlag=false;
        for(int j=0; j<Object.n; j++)
        {
            for(int k=0; k<Object.n; k++)
            {
                if(i!=ObjectNumber)
                if(
                    (
                     Object.matrix[0][j]==ObjectCache[i].matrix[0][k]
                                        &&
                     Object.matrix[1][j]==ObjectCache[i].matrix[1][k]
                    )
                                        ||
                    (
                     Object.matrix[1][j]==getmaxy()
                    )
                  )
                   {
                       if(CheckFlag==true)
                       {
                            ObjectTranslateFlag[ObjectNumber]=false;
                            BreakFlag=true;
                            break;
                       }
                       else
                       {
                           CheckFlag=true;
                       }
                   }
            }
            if(BreakFlag==true)
            break;
        }
        if(BreakFlag==true)
        break;
    }
}

void Objects::drawFrame()
{
    Transforms T;
    for(int i=0; i<ObjectCount; i++)
    {
        checkObstacle(ObjectCache[i],i);
        draw(ObjectCache[i]);
        if(ObjectTranslateFlag[i]==true)
        {
            ObjectCache[i]=T.Translate(0,1,ObjectCache[i],ObjectCache[i].n);
        }
    }
}

void Objects::nextFrame()
{
    frame%48==0?decideObject():emptyCall();
    frame++;
}

void Objects::emptyCall(){}
