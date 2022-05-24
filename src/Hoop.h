#pragma once
#include "Entity.h"
#include "ClickableObject.h"

const color baseColor = {30, 30, 0, 255};
const Uint8 deltaR = 30;
const Uint8 deltaB = 30;
const int hoopHeight = 20;
const int hoopWidthMultiplier = 10;
const int hoopBaseWidth = 20;
const int hoopMinSize = 1;
const int hoopMaxSize = 8;
const int clipSpeed = 10;

class Hoop: public Entity {
public:
    Hoop(int xpos, int ypos, int size);
    virtual void onClick(int mouseX, int mouseY, bool mouseOver);
    virtual void onHold(int mouseX, int mouseY, bool mouseOver);
    virtual void onRelease(int mouseX, int mouseY, bool mouseOver);
    virtual void update();
private:
    int sz;
    int lastMouseX;
    int lastMouseY;
    bool pickedUp = false;
    int correctX;
    int correctY;
};