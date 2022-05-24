#pragma once
#include "Pole.h"
#include "Hoop.h"

class TowerManager: public Entity {
public:
    virtual void update();

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
};