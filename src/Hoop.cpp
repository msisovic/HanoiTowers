#include "Hoop.h"
#include <algorithm>

Hoop::Hoop(int xpos, int ypos, int size):xpos(xpos), ypos(ypos), sz(size) {
    sz = std::min(sz, hoopMaxSize);
    sz = std::max(sz, hoopMinSize);
    filledRectangles.push_back(ColorFilledRectangle(color1, xpos, ypos, hoopBaseWidth + sz * hoopWidthMultiplier, hoopHeight));
}