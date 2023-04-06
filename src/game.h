//
// Created by Oliver on 06.04.2023.
//
#include "enums.h"

#ifndef RAYLIBSTARTER_GAME_H
#define RAYLIBSTARTER_GAME_H


class game {
public:
    //all verbose functions to call
    void update();
    void loadLevel(int levelID);

private:
    //everything else
    globalGameState state;
};


#endif //RAYLIBSTARTER_GAME_H
