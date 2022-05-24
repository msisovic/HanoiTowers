#pragma once
#include "TowerManager.h"

const int tmButtonWidth = 50;
const int tmButtonHeight = 50;
const color tmButtonColor = {0, 0, 0, 0};

class TowerManagerButton: public Entity {
public:
    void action();
    TowerManagerButton(int xpos, int ypos, TowerManager* towMan);
    virtual void onClick(int mouseX, int mouseY, bool mouseOver);

private:
    TowerManager* towerManager;
};