#pragma once
#include "TowerManager.h"

const int tmButtonWidth = 150;
const int tmButtonHeight = 50;
const color tmButtonColor = {0, 0, 0, 0};
const color tmButtonTextColor = {255, 255, 255, 255};

class TowerManagerButton: public Entity {
public:
    virtual void action() = 0;
    TowerManagerButton(int xpos, int ypos, TowerManager* towMan);
    virtual void onClick(int mouseX, int mouseY, bool mouseOver);

protected:
    TowerManager* towerManager;
};

class TMBRestart: public TowerManagerButton {
public:
    TMBRestart(int xpos, int ypos, TowerManager* towMan): TowerManagerButton(xpos, ypos, towMan) {
        messages.push_back(Message(tmButtonTextColor, "Restart", xpos, ypos, tmButtonWidth, tmButtonHeight));
    };
    virtual void action();
};

class TMBIncrease: public TowerManagerButton {
public:
    TMBIncrease(int xpos, int ypos, TowerManager* towMan): TowerManagerButton(xpos, ypos, towMan) {
        messages.push_back(Message(tmButtonTextColor, "Povecaj", xpos, ypos, tmButtonWidth, tmButtonHeight));
    };
    virtual void action();
};

class TMBDecrease: public TowerManagerButton {
public:
    TMBDecrease(int xpos, int ypos, TowerManager* towMan): TowerManagerButton(xpos, ypos, towMan) {
        messages.push_back(Message(tmButtonTextColor, "Smanji", xpos, ypos, tmButtonWidth, tmButtonHeight));
    };
    virtual void action();
};

class TMBSolve: public TowerManagerButton {
public:
    TMBSolve(int xpos, int ypos, TowerManager* towMan): TowerManagerButton(xpos, ypos, towMan) {
        messages.push_back(Message(tmButtonTextColor, "Resenje", xpos, ypos, tmButtonWidth, tmButtonHeight));
    };
    virtual void action();
};