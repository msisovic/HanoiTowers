#pragma once
#include "DrawableObject.h"
#include "ClickableObject.h"

const color color1={255,0,0,255};
const int hoopHeight = 20;
const int hoopWidthMultiplier = 10;
const int hoopBaseWidth = 20;
const int hoopMinSize = 1;
const int hoopMaxSize = 8;

class Hoop: public DrawableObject {
public:
    Hoop(int xpos, int ypos, int size);
    virtual void onClick(int mouseX, int mouseY, bool mouseOver);
    virtual void onHold(int mouseX, int mouseY, bool mouseOver);
    virtual void onRelease(int mouseX, int mouseY, bool mouseOver);
private:
    int sz;
    int lastMouseX;
    int lastMouseY;
    bool pickedUp = false;
};