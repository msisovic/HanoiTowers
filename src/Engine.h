#pragma once
#include "WindowRenderer.h"
#include "Utils.h"
#include "Entity.h"
#include "ClickableObject.h"

const int tickDelay = 5;

class Engine {
public:
    Engine(const char *name, int width, int height);
    ~Engine();
    void run();
    void setBackgroundColor(color c);

    void addEntity(Entity* obj);

private:
    color backgroundColor;
    WindowRenderer* windowRenderer;
    bool running;
    std::vector<Entity*> entities;

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