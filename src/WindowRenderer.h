#pragma once

#include <SDL2/SDL.h>
#include "Utils.h"
#include "Entity.h"

class WindowRenderer {
public:
    WindowRenderer(const char *title, int width, int height);
    ~WindowRenderer();

    void clearWithColor(color c);
    void renderObject(const Entity& object);
    void render();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};