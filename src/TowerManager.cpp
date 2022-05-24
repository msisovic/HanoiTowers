#include "TowerManager.h"
#include <iostream>
#include <algorithm>

void TowerManager::solve(){
    restartGame();
    fromPoleVector.clear();
    toPoleVector.clear();
    solveMode = true;
    recursiveSolve(numberOfHoops, 0, 1, 2);
    skipFrameCounter = 0;
}

void TowerManager::recursiveSolve(int n, int fromPole, int toPole, int helpPole){
    if(n == 0) {
        return;
    }
    recursiveSolve(n-1, fromPole, helpPole, toPole);
    fromPoleVector.push_back(fromPole);
    toPoleVector.push_back(toPole);
    recursiveSolve(n-1, helpPole, toPole, fromPole);
}

void TowerManager::increaseHoops(){
    numberOfHoops++;
    numberOfHoops = std::min(numberOfHoops, maxHoops);
    restartGame();
}

void TowerManager::decreaseHoops(){
    numberOfHoops--;
    numberOfHoops = std::max(numberOfHoops, minHoops);
    restartGame();
}

void TowerManager::addButton(Entity* button){
    buttons.push_back(button);
    entityManager->addEntity(button);
}

void TowerManager::restartGame(){
    clearGame();
    initHoops(numberOfHoops);
    addAllEntities();
}

void TowerManager::clearGame(){
    solveMode = false;
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
    for(auto button: buttons){
        entityManager->addEntity(button);
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
    if(solveMode){
        if(skipFrameCounter<skipFramesForSolve){
            skipFrameCounter++;
            return;
        }
        skipFrameCounter = 0;
        if(stepCount<fromPoleVector.size()){
            int fromPole = fromPoleVector[stepCount], toPole = toPoleVector[stepCount];
            Hoop* curHoop = poles[fromPole]->popHoop();
            poles[toPole]->pushHoop(curHoop);
            stepCount++;
            return;
        }
        else{
            solveMode = false;
        }
    }
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
