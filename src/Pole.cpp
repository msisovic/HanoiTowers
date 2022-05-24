#include "Pole.h"
#include <iostream>

Pole::Pole(int xpos, int ypos): Entity(xpos, ypos, poleWidth, poleHeight) {
    SDL_Rect rect;

    rect.x = xpos;
    rect.y = ypos + poleHeight - poleThickness;
    rect.h = poleThickness;
    rect.w = poleWidth;
    filledRectangles.push_back(ColorFilledRectangle(poleColor, rect));
    
    rect.x = xpos + poleWidth/2 - poleThickness/2;
    rect.y = ypos;
    rect.h = poleHeight;
    rect.w = poleThickness;
    filledRectangles.push_back(ColorFilledRectangle(poleColor, rect));

    poleBaseX = xpos + poleWidth/2;
    poleBaseY = ypos + poleHeight - poleThickness;
}

bool Pole::pushHoop(Hoop* hoop) {
    if(!hoops.empty() && hoops.back()->getSize()<hoop->getSize()){
        return false;
    }
    hoops.push_back(hoop);
    stackHeight += hoop->getHeight();
    int hWidth = hoop->getWidth();
    hoop->setCorrectX(poleBaseX - hWidth/2);
    hoop->setCorrectY(poleBaseY - stackHeight);
    ready = false;
    return true;
}

void Pole::onRelease(int mouseX, int mouseY, bool mouseOver) {
    if(mouseOver){
        ready = true;
    }
}

bool Pole::isReady(){
    return ready;
}

void Pole::setReady(bool isReady) {
    ready = isReady;
}

bool Pole::isSourcing() {
    return sourcing;
}

void Pole::popHoop() {
    if(hoops.empty()) {
        return;
    }
    stackHeight -= hoops.back()->getHeight();
    hoops.pop_back();
}

void Pole::setSourcing(bool isSourcing) {
    sourcing = isSourcing;
}

void Pole::onHold(int mouseX, int mouseY, bool mouseOver) {
    if(!hoops.empty() && hoops.back()->isPickedUp()){
        sourcing = true;
    }
}