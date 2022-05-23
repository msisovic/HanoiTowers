#pragma once

#include <SDL2/SDL.h>
#include "Utils.h"

class WindowRenderer {
public:
    WindowRenderer(const char *title, int width, int height);
    ~WindowRenderer();

    void clearWithColor(color c);
    void render();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};