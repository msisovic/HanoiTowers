#pragma once
#include "Utils.h"
#include <SDL2/SDL.h>
#include <vector>

struct coloredRectangle {
    color col;
    SDL_Rect rect;
};

class DrawableObject {
public:
    virtual std::vector<coloredRectangle> getRectangles() = 0;
};