#include "DrawableObject.h"

const color& ColorFilledRectangle::getCol() {
    return col;
}
    
const SDL_Rect& ColorFilledRectangle::getRect() {
    return rect;
}

const std::vector<ColorFilledRectangle>& DrawableObject::getFilledRectangles() const {
    return filledRectangles;
}

ColorFilledRectangle::ColorFilledRectangle(color col, int x, int y, int w, int h): col(col) {
    rect.x = x, rect.y = y, rect.w = w, rect.h = h;
}

ColorFilledRectangle::ColorFilledRectangle(color col, SDL_Rect rect): col(col), rect(rect) {

}