#pragma once
#include "WindowRenderer.h"
#include "Utils.h"
#include "DrawableObject.h"

class Engine {
public:
    Engine(const char *name, int width, int height);
    ~Engine();
    void run();
    void setBackgroundColor(color c);

    void addToRenderingQueue(DrawableObject obj);

private:
    color backgroundColor;
    WindowRenderer* windowRenderer;
    bool running;
    std::vector<DrawableObject> renderingQueue;

    void clearFrame();
    void render();
};