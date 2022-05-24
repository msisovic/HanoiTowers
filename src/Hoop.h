#pragma once
#include "DrawableObject.h"

const color color1={255,0,0,255};
const int hoopHeight = 20;
const int hoopWidthMultiplier = 10;
const int hoopBaseWidth = 20;
const int hoopMinSize = 1;
const int hoopMaxSize = 8;

class Hoop: public DrawableObject{
public:
    Hoop(int xpos, int ypos, int size);
private:
    int xpos;
    int ypos;
    int sz;
};