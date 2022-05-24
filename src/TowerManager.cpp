#include "TowerManager.h"
#include <iostream>

void TowerManager::update() {
    catchHoop();
    if(caughtHoop != nullptr) {
        if(tryToStoreHoop()){
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