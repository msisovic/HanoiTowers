#include "Hoop.h"
#include <algorithm>
#include <iostream>

Hoop::Hoop(int xpos, int ypos, int size): DrawableObject(xpos, ypos), sz(size) {
    sz = std::min(sz, hoopMaxSize);
    sz = std::max(sz, hoopMinSize);
    width = hoopBaseWidth + sz * hoopWidthMultiplier;
    height = hoopHeight;
    filledRectangles.push_back(ColorFilledRectangle(color1, xpos, ypos, width, hoopHeight));
}

void Hoop::onClick(int mouseX, int mouseY, bool mouseOver) {
    if(!mouseOver) {
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
    pickedUp = false;
}