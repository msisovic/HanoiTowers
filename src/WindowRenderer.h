#pragma once

#include <SDL2/SDL.h>
#include "Utils.h"
#include "Entity.h"
#include <SDL2/SDL_TTF.h>

const int fontSize = 60;

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
    TTF_Font* font;
};