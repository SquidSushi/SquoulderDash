//
// Created by Oliver on 06.04.2023.
//

#ifndef RAYLIBSTARTER_ENUMS_H
#define RAYLIBSTARTER_ENUMS_H

#endif //RAYLIBSTARTER_ENUMS_H

enum tileID{
    tileAir = 0,
    tileSolidWall = 2,
    tileSoftWall = 1,
    tileRock = 3
};

enum globalGameState {
    mainMenu,
    gamePlay,
    pause,
    settingsMenu
};
