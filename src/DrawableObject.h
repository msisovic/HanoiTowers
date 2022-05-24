#pragma once
#include "Utils.h"
#include <SDL2/SDL.h>
#include <vector>

class ColorFilledRectangle {
public:
    ColorFilledRectangle(color col, SDL_Rect rect);
    ColorFilledRectangle(color col, int x, int y, int w, int h);
    const color& getCol();
    const SDL_Rect& getRect();

private:
    color col;
    SDL_Rect rect;
};

class DrawableObject {
public:
    const std::vector<ColorFilledRectangle>& getFilledRectangles() const;

protected:
    std::vector<ColorFilledRectangle> filledRectangles;
};