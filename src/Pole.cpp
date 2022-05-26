#include "Pole.h"
#include <iostream>

bool Pole::isEmpty(){
    return hoops.empty();
}

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
    if(!hoops.empty()) {
        hoops.back()->setCanBePickedUp(false);
    }
    hoop->setCanBePickedUp(true);
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

Hoop* Pole::popHoop() {
    if(hoops.empty()) {
        return nullptr;
    }
    stackHeight -= hoops.back()->getHeight();
    Hoop* poppedHoop = hoops.back();
    hoops.pop_back();

    if(!hoops.empty()){
        hoops.back()->setCanBePickedUp(true);
    }

    return poppedHoop;
}

void Pole::setSourcing(bool isSourcing) {
    sourcing = isSourcing;
}

void Pole::onHold(int mouseX, int mouseY, bool mouseOver) {
    if(!hoops.empty() && hoops.back()->isPickedUp()){
        sourcing = true;
    }
}