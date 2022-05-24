#include <iostream>
#include <SDL2/SDL.h>
#include "Engine.h"
#include "Hoop.h"
#include "Pole.h"
#include "TowerManager.h"

void init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
}

const char* name = "Towers of Hanoi";
const int windowWidth = 640;
const int windowHeight = 480;
color backgroundColor = {255, 255, 255, 255};

int main(int argv, char** args) {
    init();

    EntityManager entityManager;

    Engine engine(name, windowWidth, windowHeight, &entityManager);

    TowerManager towerManager;
    entityManager.addEntity(&towerManager);

    TowerManagerDisplay tmDisplay(windowWidth/2, 350, &towerManager);
    entityManager.addEntity(&tmDisplay);

    Pole pole1(50, 100);
    Pole pole2(250, 100);
    Pole pole3(450, 100);
    entityManager.addEntity(&pole1);
    entityManager.addEntity(&pole2);
    entityManager.addEntity(&pole3);
    towerManager.poles.push_back(&pole1);
    towerManager.poles.push_back(&pole2);
    towerManager.poles.push_back(&pole3);

    Hoop hoop1(100, 100, 1);
    Hoop hoop2(100, 120, 2);
    Hoop hoop3(100, 140, 3);
    Hoop hoop4(100, 160, 4);
    Hoop hoop5(100, 180, 5);
    Hoop hoop6(100, 200, 6);
    Hoop hoop7(100, 220, 7);
    Hoop hoop8(100, 240, 8);
    entityManager.addEntity(&hoop1);
    entityManager.addEntity(&hoop2);
    entityManager.addEntity(&hoop3);
    entityManager.addEntity(&hoop4);
    entityManager.addEntity(&hoop5);
    entityManager.addEntity(&hoop6);
    entityManager.addEntity(&hoop7);
    entityManager.addEntity(&hoop8);
    towerManager.hoops.push_back(&hoop1);
    towerManager.hoops.push_back(&hoop2);
    towerManager.hoops.push_back(&hoop3);
    towerManager.hoops.push_back(&hoop4);
    towerManager.hoops.push_back(&hoop5);
    towerManager.hoops.push_back(&hoop6);
    towerManager.hoops.push_back(&hoop7);
    towerManager.hoops.push_back(&hoop8);
    pole1.pushHoop(&hoop8);
    pole1.pushHoop(&hoop7);
    pole1.pushHoop(&hoop6);
    pole1.pushHoop(&hoop5);
    pole1.pushHoop(&hoop4);
    pole1.pushHoop(&hoop3);
    pole1.pushHoop(&hoop2);
    pole1.pushHoop(&hoop1);

    engine.setBackgroundColor(backgroundColor);
    engine.run();

    return 0;
}