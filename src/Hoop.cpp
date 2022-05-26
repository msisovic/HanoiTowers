#include "Hoop.h"
#include <algorithm>
#include <iostream>

void Hoop::setCanBePickedUp(bool canBePU) {
    canBePickedUp = canBePU;
}

Hoop::Hoop(int xpos, int ypos, int size): Entity(xpos, ypos), sz(size) {
    sz = std::min(sz, hoopMaxSize);
    sz = std::max(sz, hoopMinSize);
    correctX = xpos;
    correctY = ypos;
    width = hoopBaseWidth + sz * hoopWidthMultiplier;
    height = hoopHeight;

    int deltaRWeight = sz - hoopMinSize;
    int deltaBWeight = hoopMaxSize - sz;
    color hoopColor = {(Uint8)(baseColor.r + deltaR*deltaRWeight), baseColor.g, (Uint8)(baseColor.b + deltaB*deltaBWeight), baseColor.a};

    filledRectangles.push_back(ColorFilledRectangle(hoopColor, xpos, ypos, width, hoopHeight));
}

void Hoop::onClick(int mouseX, int mouseY, bool mouseOver) {
    if(!mouseOver || !canBePickedUp) {
        return;
    }
    lastMouseX = mouseX, lastMouseY = mouseY;
    pickedUp = true;
}

void Hoop::onHold(int mouseX, int mouseY, bool mouseOver) {
    if(!pickedUp) {
        return;
    }
    int dx = mouseX - lastMouseX, dy = mouseY - lastMouseY;
    lastMouseX = mouseX, lastMouseY = mouseY;
    deltaPos(dx, dy);
}

void Hoop::onRelease(int mouseX, int mouseY, bool mouseOver) {
    if(pickedUp){
        setDropped(true);
    }
    pickedUp = false;
}

void Hoop::update() {
    if(!pickedUp && (xpos!=correctX || ypos!=correctY)) {
        int dx = abs(correctX - xpos), dy = abs(correctY - ypos);
        int speedX = clipSpeed * dx / (dx + dy), speedY = clipSpeed - speedX;
        dx = std::min(dx, speedX), dy = std::min(dy, speedY);
        if(xpos > correctX) {
            dx *= -1;
        }
        if(ypos > correctY) {
            dy *= -1;
        }

        deltaPos(dx, dy);
    }
}

void Hoop::setCorrectX(int x) {
    correctX = x;
}

void Hoop::setCorrectY(int y) {
    correctY = y;
}

bool Hoop::isPickedUp() {
    return pickedUp;
}

int Hoop::getSize() {
    return sz;
}

bool Hoop::isDropped() {
    return dropped;
}

void Hoop::setDropped(bool isDropped) {
    dropped = isDropped;
}