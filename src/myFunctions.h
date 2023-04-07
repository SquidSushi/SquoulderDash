//
// Created by mrbau on 07.04.2023.
//
#include "raylib.h"

#ifndef RAYLIBSTARTER_MYFUNCTIONS_H
#define RAYLIBSTARTER_MYFUNCTIONS_H

#endif //RAYLIBSTARTER_MYFUNCTIONS_H

Vector2 GetVmouse(float scale, Rectangle canvas) {
    Vector2 r = {(GetMouseX() + GetMouseDelta().x - canvas.x) / scale, (GetMouseY() + GetMouseDelta().y - canvas.y) / scale};
    return r;
}