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
color backgroundColor = {255, 255, 255, 255};

int main(int argv, char** args) {
    init();

    Engine engine(name, windowWidth, windowHeight);
    Hoop hoop1(100, 100, 1);
    Hoop hoop2(100, 120, 2);
    Hoop hoop3(100, 140, 3);
    Hoop hoop4(100, 160, 4);
    Hoop hoop5(100, 180, 5);
    Hoop hoop6(100, 200, 6);
    Hoop hoop7(100, 220, 7);
    Hoop hoop8(100, 240, 8);
    engine.addEntity(&hoop1);
    engine.addEntity(&hoop2);
    engine.addEntity(&hoop3);
    engine.addEntity(&hoop4);
    engine.addEntity(&hoop5);
    engine.addEntity(&hoop6);
    engine.addEntity(&hoop7);
    engine.addEntity(&hoop8);

    engine.setBackgroundColor(backgroundColor);
    engine.run();

    return 0;
}