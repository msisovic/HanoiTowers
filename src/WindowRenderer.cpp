#include "WindowRenderer.h"

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