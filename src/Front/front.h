#ifndef front_H
#define front_H
#include <windows.h>
#define height 350
#define width 400

const COLORREF bkcolor =   RGB(255, 255,255);
const int TxtBoxStyle = WS_CHILD | WS_VISIBLE |  ES_CENTER | WS_BORDER;
const int ButtonStyle = WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON;

struct ShapesD {
    int Xpos;
    int ypos;
    int sizewidth;
    int sizeheight;
  
    double centerX ();
    double centery();
    double centeryoffset(float offset);
};


#endif