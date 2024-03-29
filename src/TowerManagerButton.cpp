#include "TowerManagerButton.h"

void TowerManagerButton::onClick(int mouseX, int mouseY, bool mouseOver){
    if(mouseOver) {
        action();
    }
}

TowerManagerButton::TowerManagerButton(int xpos, int ypos, TowerManager* towMan): Entity(xpos, ypos, tmButtonWidth, tmButtonHeight) {
    towerManager = towMan;
    filledRectangles.push_back(ColorFilledRectangle(tmButtonColor, xpos, ypos, tmButtonWidth, tmButtonHeight));
}

void TMBRestart::action(){
    towerManager->restartGame();
}

void TMBIncrease::action(){
    towerManager->increaseHoops();
}

void TMBDecrease::action(){
    towerManager->decreaseHoops();
}

void TMBSolve::action(){
    towerManager->solve();
}