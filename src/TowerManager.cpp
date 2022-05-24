#include "TowerManager.h"
#include <iostream>

void TowerManager::restartGame(){
    clearGame();
    initHoops(numberOfHoops);
    addAllEntities();
}

void TowerManager::clearGame(){
    entityManager->clearEntityList();
    stepCount = 0;
    for(auto pole : poles){
        while(!(pole->isEmpty())){
            pole->popHoop();
        }
    }
    for(auto hoop : hoops){
        delete hoop;
    }
    hoops.clear();
}

void TowerManager::initPoles(){
    Pole* pole1 = new Pole(50, 100);
    Pole* pole2 = new Pole(250, 100);
    Pole* pole3 = new Pole(450, 100);
    poles.push_back(pole1);
    poles.push_back(pole2);
    poles.push_back(pole3);
}

void TowerManager::addAllEntities(){
    entityManager->addEntity(this);
    for(auto pole : poles) {
        entityManager->addEntity(pole);
    }
    for(auto hoop : hoops){
        entityManager->addEntity(hoop);
    }
}

void TowerManager::initHoops(int number) {
    for(int i=number; i>0; i--){
        Hoop* hoop = new Hoop(100,100,i);
        hoops.push_back(hoop);
        poles[0]->pushHoop(hoop);
    }
}

TowerManager::TowerManager(EntityManager* entMan){
    entityManager = entMan;

    numberOfHoops = defaultHoopNumber;
    numberOfHoops = std::max(numberOfHoops, minHoops);
    numberOfHoops = std::min(numberOfHoops, maxHoops);

    initPoles();
    initHoops(numberOfHoops);
    addAllEntities();
}

void TowerManager::update() {
    catchHoop();
    if(caughtHoop != nullptr) {
        if(tryToStoreHoop()){
            stepCount++;
            popSource();
        }
        stopSourcing();
    }
    reset();
}

bool TowerManager::tryToStoreHoop(){
    for(auto pole : poles) {
        if(pole->isReady() && pole->isSourcing() == false){
            if(pole->pushHoop(caughtHoop)){
                return true;
            }
        }
    }
    return false;
}

void TowerManager::catchHoop(){
    for(auto hoop : hoops) {
        if(hoop->isDropped()) {
            caughtHoop = hoop;
        }
    }
}

void TowerManager::reset(){
    for(auto pole : poles) {
        pole->setReady(false);
    }
    for(auto hoop : hoops) {
        hoop->setDropped(false);
    }
    caughtHoop = nullptr;
}

void TowerManager::popSource(){
    for(auto pole : poles){
        if(pole->isSourcing()) {
            pole->popHoop();
        }
    }
}

void TowerManager::stopSourcing() {
    for(auto pole : poles){
        pole->setSourcing(false);
    }
}

TowerManagerDisplay::TowerManagerDisplay(int xpos, int ypos, TowerManager* towMan): Entity(xpos, ypos, tmWidth, tmHeight) {
    this->xpos -= tmWidth/2;
    xpos -= tmWidth/2;
    towerManager = towMan;
    messages.push_back(Message(tmColor, xpos, ypos, tmWidth, tmHeight));
}

void TowerManagerDisplay::update() {
    messages[0].updateText(tmBaseMessage + std::to_string(towerManager->getStepCount()));
}

int TowerManager::getStepCount() const {
    return stepCount;
};
