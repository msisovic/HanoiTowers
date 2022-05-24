#include "Engine.h"

Engine::Engine(const char *name, int width, int height): running(true) {
    windowRenderer = new WindowRenderer(name, width, height);
};

Engine::~Engine(){
    delete windowRenderer;
}

void Engine::run() {
    while(running) {
        SDL_Delay(30);
        render();
    }
}

void Engine::render(){
    clearFrame();
    for(auto object : renderingQueue){
        windowRenderer->renderObject(object);
    }
    windowRenderer->render();
}

void Engine::clearFrame() {
    windowRenderer->clearWithColor(backgroundColor);
}

void Engine::setBackgroundColor(color c) {
    backgroundColor = c;
}

void Engine::addToRenderingQueue(DrawableObject obj){
    renderingQueue.push_back(obj);
}