#include <iostream>
#include <SDL2/SDL.h>
#include "Engine.h"
#include "Hoop.h"

void init() {
    SDL_Init(SDL_INIT_EVERYTHING);
}

const char* name = "Towers of Hanoi";
const int windowWidth = 640;
const int windowHeight = 480;
color backgroundColor = {255, 255, 128, 255};

int main(int argv, char** args) {
    init();

    Engine engine(name, windowWidth, windowHeight);
    engine.addToRenderingQueue(Hoop(100, 100, 2));

    engine.setBackgroundColor(backgroundColor);
    engine.run();

    return 0;
}