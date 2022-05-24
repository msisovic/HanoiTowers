#pragma once
#include "WindowRenderer.h"
#include "Utils.h"
#include "Entity.h"
#include "EntityManager.h"

const int tickDelay = 5;

class Engine {
public:
    Engine(const char *name, int width, int height, EntityManager* entityManager);
    ~Engine();
    void run();
    void setBackgroundColor(color c);

private:
    color backgroundColor;
    WindowRenderer* windowRenderer;
    bool running;
    EntityManager* entityManager;

    bool mouseDown = false;
    bool mousePressed = false;
    bool mouseReleased = false;
    int mouseX;
    int mouseY;

    void handleInput();
    void handleClicks();
    void handleUpdates();

    void clearFrame();
    void render();
};