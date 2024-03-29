#include "Entity.h"
#include <iostream>

Entity::~Entity(){
    
}

const color& ColorFilledRectangle::getCol() const {
    return col;
}
    
const SDL_Rect& ColorFilledRectangle::getRect() const {
    return rect;
}

const std::vector<ColorFilledRectangle>& Entity::getFilledRectangles() const {
    return filledRectangles;
}

ColorFilledRectangle::ColorFilledRectangle(color col, int x, int y, int w, int h): col(col) {
    rect.x = x, rect.y = y, rect.w = w, rect.h = h;
}

ColorFilledRectangle::ColorFilledRectangle(color col, SDL_Rect rect): col(col), rect(rect) {

}

void Entity::updatePos(int x, int y) {
    xpos = x, ypos = y;
    for(auto& filledRect : filledRectangles) {
        filledRect.updatePos(x,y);
    }
}

void ColorFilledRectangle::updatePos(int x, int y) {
    this->rect.x = x, this->rect.y = y;
}

void Entity::deltaPos(int dx, int dy) {
    updatePos(xpos + dx, ypos + dy);
}

void Entity::onClick(int mouseX, int mouseY, bool mouseOver) {
    
}

void Entity::onHold(int mouseX, int mouseY, bool mouseOver) {
    
}

void Entity::onRelease(int mouseX, int mouseY, bool mouseOver) {
    
}

void Entity::update() {
    
}

Message::Message(color col, int x, int y, int w, int h): col(col) {
    rect.x = x, rect.y = y, rect.w = w, rect.h = h;
}
Message::Message(color col, const std::string& text, int x, int y, int w, int h): col(col), text(text) {
    rect.x = x, rect.y = y, rect.w = w, rect.h = h;
}

void Message::updateText(const std::string& newText) {
    text = newText;
}

const std::vector<Message>& Entity::getMessages() const {
    return messages;
}

const std::string& Message::getText() const {
    return text;
}

color Message::getCol() const {
    return col;
}

SDL_Rect Message::getRect() const {
    return rect;
}