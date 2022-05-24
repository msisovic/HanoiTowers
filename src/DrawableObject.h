#pragma once
#include "Utils.h"
#include <SDL2/SDL.h>
#include <vector>

class ColorFilledRectangle {
public:
    ColorFilledRectangle(color col, SDL_Rect rect);
    ColorFilledRectangle(color col, int x, int y, int w, int h);
    const color& getCol() const;
    const SDL_Rect& getRect() const;
    void updatePos(int x, int y);

private:
    color col;
    SDL_Rect rect;
};

class DrawableObject {
public:
    DrawableObject(int xpos, int ypos, int width, int height): xpos(xpos), ypos(ypos), width(width), height(height) {};
    DrawableObject(int xpos, int ypos): xpos(xpos), ypos(ypos) {};
    const std::vector<ColorFilledRectangle>& getFilledRectangles() const;
    int getXPos() const { return xpos; };
    int getYPos() const { return ypos; };
    int getWidth() const { return width; };
    int getHeight() const { return height; };

    virtual void onClick(int mouseX, int mouseY, bool mouseOver) = 0;
    virtual void onHold(int mouseX, int mouseY, bool mouseOver) = 0;
    virtual void onRelease(int mouseX, int mouseY, bool mouseOver) = 0;
    virtual void update() = 0;

protected:
    std::vector<ColorFilledRectangle> filledRectangles;
    void updatePos(int x, int y);
    void deltaPos(int dx, int dy);

    int xpos;
    int ypos;
    int width;
    int height;
};