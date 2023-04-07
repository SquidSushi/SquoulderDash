//
// Created by Oliver on 06.04.2023.
//

#ifndef RAYLIBSTARTER_ENUMS_H
#define RAYLIBSTARTER_ENUMS_H

#endif //RAYLIBSTARTER_ENUMS_H

enum tileID{
    air = 0,
    solidWall = 2,
    softWall = 1,
    rock = 3,
    player = 4
};

enum globalGameState {
    mainMenu,
    gamePlay,
    pause,
    settingsMenu
};
