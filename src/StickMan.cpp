#include "StickMan.h"
#include <graphics.h>
#include <dos.h>
#include <iostream>

using namespace std;

StickMan::StickMan()
{
    frame=0;
    jumpFrame=0;
    runCycle=0;
    runningFactor=0;
    skipFramesFlag=0;
    jumpingFactor=getmaxy();
    M.n=12;
    /*
    M.matrix=
    {
        {32,32,32,32,0,6,64,70,0,6,64,70},
        {12,24,72,36,66,72,66,60,114,120,114,108},
        {1,1,1,1,1,1,1,1,1,1,1,1},
    };
    */
    M.matrix[0][0]=32;M.matrix[1][0]=12;M.matrix[2][0]=1;
    M.matrix[0][1]=32;M.matrix[1][1]=24;M.matrix[2][1]=1;
    M.matrix[0][2]=32;M.matrix[1][2]=72;M.matrix[2][2]=1;
    M.matrix[0][3]=32;M.matrix[1][3]=36;M.matrix[2][3]=1;
    M.matrix[0][4]=0;M.matrix[1][4]=66;M.matrix[2][4]=1;
    M.matrix[0][5]=6;M.matrix[1][5]=72;M.matrix[2][5]=1;
    M.matrix[0][6]=64;M.matrix[1][6]=66;M.matrix[2][6]=1;
    M.matrix[0][7]=70;M.matrix[1][7]=60;M.matrix[2][7]=1;
    M.matrix[0][8]=0;M.matrix[1][8]=114;M.matrix[2][8]=1;
    M.matrix[0][9]=6;M.matrix[1][9]=120;M.matrix[2][9]=1;
    M.matrix[0][10]=64;M.matrix[1][10]=114;M.matrix[2][10]=1;
    M.matrix[0][11]=70;M.matrix[1][11]=108;M.matrix[2][11]=1;
}

void StickMan::drawFrame()
{
    circle(M.matrix[0][0],M.matrix[1][0],12);                         //head
    line(M.matrix[0][1],M.matrix[1][1],M.matrix[0][2],M.matrix[1][2]);//body
    line(M.matrix[0][3],M.matrix[1][3],M.matrix[0][4],M.matrix[1][4]);//left hand
    line(M.matrix[0][4],M.matrix[1][4],M.matrix[0][5],M.matrix[1][5]);//left hand palm
    line(M.matrix[0][3],M.matrix[1][3],M.matrix[0][6],M.matrix[1][6]);//right hand
    line(M.matrix[0][6],M.matrix[1][6],M.matrix[0][7],M.matrix[1][7]);//right hand palm
    line(M.matrix[0][2],M.matrix[1][2],M.matrix[0][8],M.matrix[1][8]);//left leg
    line(M.matrix[0][8],M.matrix[1][8],M.matrix[0][9],M.matrix[1][9]);//left leg feet
    line(M.matrix[0][2],M.matrix[1][2],M.matrix[0][10],M.matrix[1][10]);//right leg
    line(M.matrix[0][10],M.matrix[1][10],M.matrix[0][11],M.matrix[1][11]);//right leg feet
}

void StickMan::moveRightLegs(float rotationFactor)
{
    Matrix rotate;
    rotate.n=4;
    /*
    rotate.matrix=
    {
        {M.matrix[0][2],M.matrix[0][10],M.matrix[0][10],M.matrix[0][11]},
        {M.matrix[1][2],M.matrix[1][10],M.matrix[1][10],M.matrix[1][11]},
        {1,1,1,1}
    };
    */
    rotate.matrix[0][0]=M.matrix[0][2];rotate.matrix[1][0]=M.matrix[1][2];rotate.matrix[2][0]=1;
    rotate.matrix[0][1]=M.matrix[0][10];rotate.matrix[1][1]=M.matrix[1][10];rotate.matrix[2][1]=1;
    rotate.matrix[0][2]=M.matrix[0][10];rotate.matrix[1][2]=M.matrix[1][10];rotate.matrix[2][2]=1;
    rotate.matrix[0][3]=M.matrix[0][11];rotate.matrix[1][3]=M.matrix[1][11];rotate.matrix[2][3]=1;
    rotate=T.Rotate(rotationFactor,rotate,rotate.n);
    M.matrix[0][2]=rotate.matrix[0][0];
    M.matrix[0][10]=rotate.matrix[0][1];
    M.matrix[0][10]=rotate.matrix[0][2];
    M.matrix[0][11]=rotate.matrix[0][3];
    M.matrix[1][2]=rotate.matrix[1][0];
    M.matrix[1][10]=rotate.matrix[1][1];
    M.matrix[1][10]=rotate.matrix[1][2];
    M.matrix[1][11]=rotate.matrix[1][3];
}

void StickMan::moveLeftLegs(float rotationFactor)
{
    Matrix rotate;
    rotate.n=4;
    /*
    rotate.matrix=
    {
        {M.matrix[0][2],M.matrix[0][8],M.matrix[0][8],M.matrix[0][9]},
        {M.matrix[1][2],M.matrix[1][8],M.matrix[1][8],M.matrix[1][9]},
        {1,1,1,1}
    };
    */
    rotate.matrix[0][0]=M.matrix[0][2];rotate.matrix[1][0]=M.matrix[1][2];rotate.matrix[2][0]=1;
    rotate.matrix[0][1]=M.matrix[0][8];rotate.matrix[1][1]=M.matrix[1][8];rotate.matrix[2][1]=1;
    rotate.matrix[0][2]=M.matrix[0][8];rotate.matrix[1][2]=M.matrix[1][8];rotate.matrix[2][2]=1;
    rotate.matrix[0][3]=M.matrix[0][9];rotate.matrix[1][3]=M.matrix[1][9];rotate.matrix[2][3]=1;

    rotate=T.Rotate(rotationFactor,rotate,rotate.n);
    M.matrix[0][2]=rotate.matrix[0][0];
    M.matrix[0][8]=rotate.matrix[0][1];
    M.matrix[0][8]=rotate.matrix[0][2];
    M.matrix[0][9]=rotate.matrix[0][3];
    M.matrix[1][2]=rotate.matrix[1][0];
    M.matrix[1][8]=rotate.matrix[1][1];
    M.matrix[1][8]=rotate.matrix[1][2];
    M.matrix[1][9]=rotate.matrix[1][3];
}

void StickMan::moveRightHands(float rotationFactor)
{
    Matrix rotate;
    rotate.n=4;
    /*
    rotate.matrix=
    {
        {M.matrix[0][3],M.matrix[0][6],M.matrix[0][6],M.matrix[0][7]},
        {M.matrix[1][3],M.matrix[1][6],M.matrix[1][6],M.matrix[1][7]},
        {1,1,1,1}
    };
    */
    rotate.matrix[0][0]=M.matrix[0][3];rotate.matrix[1][0]=M.matrix[1][3];rotate.matrix[2][0]=1;
    rotate.matrix[0][1]=M.matrix[0][6];rotate.matrix[1][1]=M.matrix[1][6];rotate.matrix[2][1]=1;
    rotate.matrix[0][2]=M.matrix[0][6];rotate.matrix[1][2]=M.matrix[1][6];rotate.matrix[2][2]=1;
    rotate.matrix[0][3]=M.matrix[0][7];rotate.matrix[1][3]=M.matrix[1][7];rotate.matrix[2][3]=1;

    rotate=T.Rotate(rotationFactor,rotate,rotate.n);
    M.matrix[0][3]=rotate.matrix[0][0];
    M.matrix[0][6]=rotate.matrix[0][1];
    M.matrix[0][6]=rotate.matrix[0][2];
    M.matrix[0][7]=rotate.matrix[0][3];
    M.matrix[1][3]=rotate.matrix[1][0];
    M.matrix[1][6]=rotate.matrix[1][1];
    M.matrix[1][6]=rotate.matrix[1][2];
    M.matrix[1][7]=rotate.matrix[1][3];
}

void StickMan::moveLeftHands(float rotationFactor)
{
    Matrix rotate;
    rotate.n=4;
    /*
    rotate.matrix=
    {
        {M.matrix[0][3],M.matrix[0][4],M.matrix[0][4],M.matrix[0][5]},
        {M.matrix[1][3],M.matrix[1][4],M.matrix[1][4],M.matrix[1][5]},
        {1,1,1,1}
    };
    */
    rotate.matrix[0][0]=M.matrix[0][3];rotate.matrix[1][0]=M.matrix[1][3];rotate.matrix[2][0]=1;
    rotate.matrix[0][1]=M.matrix[0][4];rotate.matrix[1][1]=M.matrix[1][4];rotate.matrix[2][1]=1;
    rotate.matrix[0][2]=M.matrix[0][4];rotate.matrix[1][2]=M.matrix[1][4];rotate.matrix[2][2]=1;
    rotate.matrix[0][3]=M.matrix[0][5];rotate.matrix[1][3]=M.matrix[1][5];rotate.matrix[2][3]=1;

    rotate=T.Rotate(rotationFactor,rotate,rotate.n);
    M.matrix[0][3]=rotate.matrix[0][0];
    M.matrix[0][4]=rotate.matrix[0][1];
    M.matrix[0][4]=rotate.matrix[0][2];
    M.matrix[0][5]=rotate.matrix[0][3];
    M.matrix[1][3]=rotate.matrix[1][0];
    M.matrix[1][4]=rotate.matrix[1][1];
    M.matrix[1][4]=rotate.matrix[1][2];
    M.matrix[1][5]=rotate.matrix[1][3];
}

void StickMan::switchRunCycle()
{
    if(runCycle==1)
    {
        runCycle=0;
    }
    else
    {
        runCycle=1;
    }
}

void StickMan::staticRun()
{
    runningFactor=8;
    if(frame%10==0)
    {
        switchRunCycle();
    }
    if(runCycle==0)
    {
        moveRightLegs(-runningFactor);
        moveLeftLegs(runningFactor);
        moveRightHands(-runningFactor);
        moveLeftHands(runningFactor);
    }
    else
    {
        moveRightLegs(runningFactor);
        moveLeftLegs(-runningFactor);
        moveRightHands(runningFactor);
        moveLeftHands(-runningFactor);
    }
}

void StickMan::translate(int translationFactorx,int translationFactory)
{
    M.n=12;
    M=T.Translate(translationFactorx,translationFactory,M,M.n);
}

//void StickMan::reflect(int axis);

void StickMan::keyPressAction(int key)
{
    switch(key)
    {
        case 72:translate(0,-2);    //up
        break;
        case 75:translate(-2,0);   //left
        break;
        case 77:translate(2,0);   //right
        break;
        case 80:translate(0,2);   //down
        break;
        default:;
    }
    staticRun();
    frame++;
}

void StickMan::nextFrame()
{

}
