//
// Created by Oliver on 06.04.2023.
//
#pragma once
#include <vector>
#include "enums.h"
#include "raylib.h"
#include "rock.h"

#ifndef RAYLIBSTARTER_GAME_H
#define RAYLIBSTARTER_GAME_H


class gameClass {
public:
    //all verbose functions to call
    void update();
    void loadLevel(int levelID);
    gameClass();

private:
    //everything else
    globalGameState state;
    std::vector<tileID> map;
    std::vector<rock> rocks;
    Music menuMusic;
    Music gameMusic;
    Vector2 playerPos;

};


#endif //RAYLIBSTARTER_GAME_H
