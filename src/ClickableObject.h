#pragma once

class ClickableObject {
public:
    virtual void onClick(int mouseX, int mouseY) = 0;
    virtual void onHold(int mouseX, int mouseY) = 0;
    virtual void onRelease(int mouseX, int mouseY) = 0;
};