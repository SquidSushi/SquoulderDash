//
// Created by Oliver on 06.04.2023.
//
#pragma once
#include <vector>
#include "enums.h"

#ifndef RAYLIBSTARTER_GAME_H
#define RAYLIBSTARTER_GAME_H


class gameClass {
public:
    //all verbose functions to call
    void update();
    void loadLevel(int levelID);

private:
    //everything else
    globalGameState state;
    std::vector<tileID> map;
};


#endif //RAYLIBSTARTER_GAME_H
