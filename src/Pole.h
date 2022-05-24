#pragma once
#include "Entity.h"
#include "Hoop.h"

const int poleWidth = 150;
const int poleHeight = 200;
const int poleThickness = 10;
const color poleColor = {0, 0, 0, 0};

class Pole: public Entity {
public:
    Pole(int xpos, int ypos);
    
    void popHoop();
    bool pushHoop(Hoop* hoop);
    bool isEmpty();

    virtual void onHold(int mouseX, int mouseY, bool mouseOver);
    virtual void onRelease(int mouseX, int mouseY, bool mouseOver);
    bool isReady();
    void setReady(bool isReady);
    bool isSourcing();
    void setSourcing(bool isSourcing);

private:
    bool ready;
    bool sourcing = false;
    std::vector<Hoop*> hoops;
    int poleBaseX;
    int poleBaseY;
    int stackHeight = 0;
};