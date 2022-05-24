#include <iostream>
#include <SDL2/SDL.h>
#include "Engine.h"
#include "Hoop.h"
#include "Pole.h"
#include "TowerManager.h"
#include "TowerManagerButton.h"

void init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
}

const char* name = "Towers of Hanoi";
const int windowWidth = 660;
const int windowHeight = 480;
color backgroundColor = {255, 255, 255, 255};

int main(int argv, char** args) {
    init();

    EntityManager entityManager;

    Engine engine(name, windowWidth, windowHeight, &entityManager);

    TowerManager towerManager(&entityManager);

    TowerManagerDisplay tmDisplay(windowWidth/2, 350, &towerManager);
    towerManager.addButton(&tmDisplay);

    TMBRestart tmButton1(10,10,&towerManager);
    towerManager.addButton(&tmButton1);
    TMBDecrease tmButton2(170,10,&towerManager);
    towerManager.addButton(&tmButton2);
    TMBIncrease tmButton3(330,10,&towerManager);
    towerManager.addButton(&tmButton3);
    TMBSolve tmButton4(490,10,&towerManager);
    towerManager.addButton(&tmButton4);

    engine.setBackgroundColor(backgroundColor);
    engine.run();

    return 0;
}