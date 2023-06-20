//
// Created by Oliver on 06.04.2023.
//
#pragma once
#include <vector>
#include "enums.h"
#include "rock.h"
#include "math.h"

#ifndef RAYLIBSTARTER_GAME_H
#define RAYLIBSTARTER_GAME_H


class gameClass {
public:
    //all verbose functions to call from main
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
    Camera2D gameCam{{0,0},{0,0},0,1};
    int age;
    int stateAge;
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
    void drawBubble(Vector2 origin, float minimumWidth, float growthWidth, int duration, float height, int delay, float minRadius, float growthRadius,
                    Color clr1, Color clr2, float cycles, float drift);
};


#endif //RAYLIBSTARTER_GAME_H
