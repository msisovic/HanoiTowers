#include "Hoop.h"
#include <algorithm>
#include <iostream>

Hoop::Hoop(int xpos, int ypos, int size): DrawableObject(xpos, ypos), sz(size) {
    sz = std::min(sz, hoopMaxSize);
    sz = std::max(sz, hoopMinSize);
    correctX = xpos;
    correctY = ypos;
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