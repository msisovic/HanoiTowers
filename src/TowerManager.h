#pragma once
#include "Pole.h"
#include "Hoop.h"

class TowerManager: public Entity {
public:
    virtual void update();
    int getStepCount() const;

//private:
    std::vector<Pole*> poles;
    std::vector<Hoop*> hoops;
    Hoop* caughtHoop = nullptr;

private:
    bool tryToStoreHoop();
    void catchHoop();
    void reset();
    void popSource();
    void stopSourcing();
    int stepCount = 0;
};

const int tmWidth = 200;
const int tmHeight = 50;
const std::string tmBaseMessage = "Broj koraka: ";
const color tmColor = {0, 0, 0, 0};

class TowerManagerDisplay: public Entity {
public:
    TowerManagerDisplay(int xpos, int ypos, TowerManager* towMan);
    virtual void update();
private:
    TowerManager* towerManager;
};