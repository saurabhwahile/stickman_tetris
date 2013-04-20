#ifndef STICKMAN_H
#define STICKMAN_H

#include "Matrix.h"
#include "Transforms.h"

class StickMan
{
public:
    int frame;
    int jumpFrame;
    int runCycle;
    int skipFramesFlag;
    int jumpingFactor;
    Matrix M;
    Transforms T;
    float runningFactor;

    StickMan();
    void drawFrame();
    void moveRightLegs(float rotationFactor);
    void moveLeftLegs(float rotationFactor);
    void moveRightHands(float rotationFactor);
    void moveLeftHands(float rotationFactor);
    void switchRunCycle();
    void staticRun();
    void translate(int translationFactorx,int translationFactory);
    void nextFrame();
    void keyPressAction(int key);
};

#endif
