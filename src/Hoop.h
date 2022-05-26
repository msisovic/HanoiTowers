#pragma once
#include "Entity.h"

const color baseColor = {0, 0, 0, 255};
const Uint8 deltaR = 36;
const Uint8 deltaB = 36;
const int hoopHeight = 20;
const int hoopWidthMultiplier = 15;
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
    void setCorrectX(int x);
    void setCorrectY(int y);
    bool isPickedUp();
    int getSize();
    bool isDropped();
    void setDropped(bool isDropped);
    void setCanBePickedUp(bool canBePU);

private:
    int sz;
    int lastMouseX;
    int lastMouseY;
    bool pickedUp = false;
    bool dropped = false;
    int correctX;
    int correctY;

    bool canBePickedUp = false;
};