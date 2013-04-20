#ifndef OBJECTS_H
#define OBJECTS_H

#include "Matrix.h"

class Objects
{
    public:
        Objects();
        Matrix Object[5];
        int frame;
        Matrix ObjectCache[100];
        int ObjectCacheType[100];
        bool ObjectTranslateFlag[100];
        int ObjectCount;
        void draw(int n);
        void draw(Matrix Object);
        void nextFrame();
        Matrix decideInitialPosition(Matrix Object);
        void drawFrame();
        void decideObject();
        void emptyCall();
        void checkObstacle(Matrix Object,int ObjectNumber);
    protected:
    private:
};

#endif // OBJECTS_H
