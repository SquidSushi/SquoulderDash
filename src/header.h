//
// Created by Oliver on 06.04.2023.
//
#pragma once
#include "raylib.h"
#include "raymath.h"

#ifndef RAYLIBSTARTER_ENUMS_H
#define RAYLIBSTARTER_ENUMS_H

#endif //RAYLIBSTARTER_ENUMS_H

enum tileID{
    tileAir = 0,
    tileSolidWall = 2,
    tileSoftWall = 1,
    tileRock = 3,
    tilePlayer = 4
};

enum globalGameState {
    mainMenu,
    gamePlay,
    pause,
    settingsMenu
};

Vector2 operator +(Vector2 a, Vector2 b){
    return Vector2Add(a,b);
}

Vector2 operator - (Vector2 a, Vector2 b){
    return Vector2Subtract(a,b);
}

Vector2 operator * (Vector2 a, float b){
    return Vector2Scale(a,b);
}

Vector2 Vector2SetLength(Vector2 a, float b){
    return Vector2Scale(Vector2Normalize(a),b);
}

Vector2 Vector2ClampLength(Vector2 vec, float min, float max){
    if (max < min){
        TraceLog(LOG_WARNING, "Vector2ClampLength has been called with inverted parameters!");
    }
    float vls = Vector2LengthSqr(vec);
    float maxs = max * max;
    float mins = min*min;
    if (vls<mins){
        return Vector2SetLength(vec,min);
    }
    if (vls>maxs){
        return Vector2SetLength(vec,max);
    }
}