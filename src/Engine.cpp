#include "Engine.h"
#include <iostream>

Engine::Engine(const char *name, int width, int height): running(true) {
    windowRenderer = new WindowRenderer(name, width, height);
};

Engine::~Engine(){
    delete windowRenderer;
}

void Engine::run() {
    while(running) {
        SDL_Delay(5);
        handleInput();
        handleClicks();
        render();
    }
}

void Engine::render(){
    clearFrame();
    for(auto& object : renderingQueue){
        windowRenderer->renderObject(*object);
    }
    windowRenderer->render();
}

void Engine::clearFrame() {
    windowRenderer->clearWithColor(backgroundColor);
}

void Engine::setBackgroundColor(color c) {
    backgroundColor = c;
}

void Engine::addToRenderingQueue(DrawableObject* obj) {
    renderingQueue.push_back(obj);
}

void Engine::handleInput() {
    mousePressed = false;
    mouseReleased = false;
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if(event.button.button == SDL_BUTTON_LEFT) {
                mouseDown = true;
                mousePressed = true;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            if(event.button.button == SDL_BUTTON_LEFT) {
                mouseDown = false;
                mouseReleased = true;
            }
            break;
        }
    }
    SDL_GetMouseState(&mouseX, &mouseY);
}

void Engine::handleClicks() {
    for(auto& object : renderingQueue){
        int xmin = object->getXPos();
        int xmax = xmin + object->getWidth();
        int ymin = object->getYPos();
        int ymax = ymin + object->getHeight();
        bool mouseOver = true;
        if(mouseX >= xmax || mouseX < xmin || mouseY >= ymax || mouseY < ymin) {
            mouseOver = false;
        }

        if(mousePressed) {
            object->onClick(mouseX, mouseY, mouseOver);
        }
        if(mouseDown) {
            object->onHold(mouseX, mouseY, mouseOver);
        }
        if(mouseReleased) {
            object->onRelease(mouseX, mouseY, mouseOver);
        }
    }
}