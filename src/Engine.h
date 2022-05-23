#pragma once
#include "WindowRenderer.h"
#include "Utils.h"

class Engine {
public:
    Engine(const char *name, int width, int height);
    ~Engine();
    void run();
    void setBackgroundColor(color c);

private:
    color backgroundColor;
    WindowRenderer* windowRenderer;
    bool running;

    void clearFrame();
    void render();
};