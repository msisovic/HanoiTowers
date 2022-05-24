#include "WindowRenderer.h"
#include <iostream>

WindowRenderer::~WindowRenderer(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_CloseFont(font);
}

WindowRenderer::WindowRenderer(const char *title, int width, int height) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);
    font = TTF_OpenFont("res/OpenSans-Regular.ttf", fontSize);
}

void WindowRenderer::clearWithColor(color c) {
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    SDL_RenderClear(renderer);
}

void WindowRenderer:: render(){
    SDL_RenderPresent(renderer);
}

void WindowRenderer::renderObject(const Entity& object){
    const std::vector<ColorFilledRectangle>& filledRects = object.getFilledRectangles();
    for(auto& filledRect : filledRects) {
        const color& col = filledRect.getCol();
        const SDL_Rect& rect = filledRect.getRect();
        SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
        SDL_RenderFillRect(renderer, &rect);
    }

    const std::vector<Message>& messages = object.getMessages();
    for(auto& message : messages) {
        std::cout<<"ok "<<message.getText()<<"\n"<<(font==nullptr)<<"\n";
        color col = message.getCol();
        SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, message.getText().c_str(), {col.r, col.g, col.b});
        SDL_Texture* messageTexture = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        SDL_Rect messageRect = message.getRect();
        SDL_RenderCopy(renderer, messageTexture, NULL, &messageRect);

        SDL_FreeSurface(surfaceMessage);
        SDL_DestroyTexture(messageTexture);
    }
}