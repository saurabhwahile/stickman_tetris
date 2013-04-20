#include <iostream>
#include<graphics.h>
#include<dos.h>

#include "Objects.h"
#include "StickMan.h"

using namespace std;

void initialize()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
}
int main()
{
    initialize();
    Objects A;
    StickMan B;
    B.translate(0,360-12);
    bool DelayFlag=false;
    for(int i=0; i<2000; i++)
    {
        cleardevice();
        A.drawFrame();
        B.drawFrame();

        if(kbhit()!=0)
        {
            DelayFlag=true;

            delay(50);
            int key=getch();
            //cout<<key;
            B.keyPressAction(key);
        }
        A.nextFrame();
        B.nextFrame();
        if(DelayFlag==false)
        {
            delay(50);
        }
        else
        {
            DelayFlag=false;
        }
    }

    getch();
    closegraph();
    return 0;
}
