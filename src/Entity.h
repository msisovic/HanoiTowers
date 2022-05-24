#pragma once
#include "Utils.h"
#include <SDL2/SDL.h>
#include <vector>
#include <string>

class Message {
public:
    Message(color col, int x, int y, int w, int h);
    Message(color col, const std::string& text, int x, int y, int w, int h);
    void updateText(const std::string& newText);
    const std::string& getText() const;
    color getCol() const;
    SDL_Rect getRect() const;

private:
    std::string text;
    color col;
    SDL_Rect rect;
};

class ColorFilledRectangle {
public:
    ColorFilledRectangle(color col, SDL_Rect rect);
    ColorFilledRectangle(color col, int x, int y, int w, int h);
    const color& getCol() const;
    const SDL_Rect& getRect() const;
    void updatePos(int x, int y);

private:
    color col;
    SDL_Rect rect;
};

class Entity {
public:
    Entity(int xpos, int ypos, int width, int height): xpos(xpos), ypos(ypos), width(width), height(height) {};
    Entity(int xpos, int ypos): xpos(xpos), ypos(ypos) {};
    Entity() {};
    virtual ~Entity();

    const std::vector<ColorFilledRectangle>& getFilledRectangles() const;
    const std::vector<Message>& getMessages() const;

    int getXPos() const { return xpos; };
    int getYPos() const { return ypos; };
    int getWidth() const { return width; };
    int getHeight() const { return height; };

    virtual void onClick(int mouseX, int mouseY, bool mouseOver);
    virtual void onHold(int mouseX, int mouseY, bool mouseOver);
    virtual void onRelease(int mouseX, int mouseY, bool mouseOver);
    virtual void update();

protected:
    std::vector<ColorFilledRectangle> filledRectangles;
    std::vector<Message> messages;
    void updatePos(int x, int y);
    void deltaPos(int dx, int dy);

    int xpos = -1;
    int ypos = -1;
    int width = 0;
    int height = 0;
};