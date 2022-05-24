#pragma once
#include "Pole.h"
#include "Hoop.h"
#include "EntityManager.h"

const int defaultHoopNumber = 8;
const int minHoops = 1;
const int maxHoops = 8;

class TowerManager: public Entity {
public:
    TowerManager(EntityManager* entMan);
    virtual void update();
    int getStepCount() const;
    void restartGame();

private:
    EntityManager* entityManager;

    void initPoles();
    void initHoops(int number);
    void addAllEntities();

    bool tryToStoreHoop();
    void catchHoop();
    void reset();
    void popSource();
    void stopSourcing();
    int stepCount = 0;

    std::vector<Pole*> poles;
    std::vector<Hoop*> hoops;
    Hoop* caughtHoop = nullptr;

    int numberOfHoops;
    void clearGame();
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