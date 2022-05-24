#include "WindowRenderer.h"
#include <iostream>

WindowRenderer::~WindowRenderer(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

WindowRenderer::WindowRenderer(const char *title, int width, int height) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);
}

void WindowRenderer::clearWithColor(color c) {
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    SDL_RenderClear(renderer);
}

void WindowRenderer:: render(){
    SDL_RenderPresent(renderer);
}

void WindowRenderer::renderObject(const DrawableObject& object){
    const std::vector<ColorFilledRectangle>& filledRects = object.getFilledRectangles();
    for(auto& filledRect : filledRects) {
        const color& col = filledRect.getCol();
        const SDL_Rect& rect = filledRect.getRect();
        SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
        SDL_RenderFillRect(renderer, &rect);
    }
}