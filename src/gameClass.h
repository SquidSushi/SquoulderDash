//
// Created by Oliver on 06.04.2023.
//
#pragma once
#include <vector>
#include "enums.h"
#include "rock.h"


#ifndef RAYLIBSTARTER_GAME_H
#define RAYLIBSTARTER_GAME_H


class gameClass {
public:
    //all verbose functions to call
    void update();
    void draw();
    void loadLevel(int levelID);
    gameClass();
    bool gameShouldClose = false;
    struct {} settings;
    int getState(){
        return this->state;
    }
private:
    //everything else
    globalGameState state;
    std::vector<tileID> map;
    std::vector<rock> rocks;
    Music menuMusic;
    Music gameMusic;
    Vector2 playerPos;
    int menuCursor = 0;
    void goToMainMenu();
    void updateMainMenu();
    void drawMainMenu();
    void goToGameplay();
    void updateGameplay();
    void drawGamePlay();
    void goToPause();
    void updatePause();
    void drawPause();
    void goToSettings();
    void updateSettings();
    void drawSettings();
    Texture texTileset;
    Texture texSoftWall;
    Texture texSoftWallWang;
    int mapColumns = 40;
};


#endif //RAYLIBSTARTER_GAME_H
