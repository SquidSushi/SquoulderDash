//
// Created by Oliver on 06.04.2023.
//

#include <string>
#include "gameClass.h"

gameClass::gameClass() {
    state = mainMenu;
    map.clear();
    menuMusic = (LoadMusicStream(""));
    gameMusic = (LoadMusicStream(""));
}

void gameClass::update() {
    if (IsMusicStreamPlaying(menuMusic)){
        UpdateMusicStream(menuMusic);
    }
    if (IsMusicStreamPlaying(gameMusic)){
        UpdateMusicStream(gameMusic);
    }
    switch (state) {
        case mainMenu:
            updateMainMenu();
            break;
        case gamePlay:
            updateGameplay();
            break;
        case pause:
            updatePause();
            break;
        default:
            if (IsKeyPressed(KEY_ENTER)) {
                this->goToMainMenu();
            }
    }
}

void gameClass::updateMainMenu() {
    int maxMenuOptions = 3;
    if (IsKeyPressed(KEY_W)) {
        menuCursor += maxMenuOptions-1;
    }
    if (IsKeyPressed(KEY_S)) {
        menuCursor++;
    }
    menuCursor %= maxMenuOptions;
    if (IsKeyPressed(KEY_ENTER)) {
        switch (menuCursor) {
            case 0: //Start Button
                this->loadLevel(0);
                this->goToGameplay();
                break;
            case 1: //Settings Button
                this->goToSettings();
                break;
            case 2: //Exit game Button
                this->gameShouldClose = true;
        }
    }

}

void gameClass::goToMainMenu() {
    menuCursor = 0;
    StopMusicStream(gameMusic);
    PlayMusicStream(menuMusic);

}

void gameClass::loadLevel(int levelID) {
    TraceLog(0, "loadLevel was called, but function isn't defined yet!");
    //TODO: Load Level


}

void gameClass::goToGameplay() {
    if (IsMusicStreamPlaying(menuMusic)) {
        StopMusicStream(menuMusic);
    }
    if (!IsMusicStreamPlaying(gameMusic)) {
        PlayMusicStream(gameMusic);
    }
    this->state = gamePlay;
}

void gameClass::goToSettings() {
    menuCursor = 0;
    this->state = settingsMenu;
}

void gameClass::draw() {
    switch (state){
        case mainMenu:
            drawMainMenu();
            break;
        case gamePlay:
            drawGamePlay();
            break;
        case settingsMenu:
            drawSettings();
            break;
        case pause:
            drawPause();
            break;
        default:
            DrawText("gameClass::draw() is very confused as to what you are trying to achieve :(",10,34,10,RED);
    }

}

void gameClass::drawMainMenu() {
    DrawRectangle(0,0,Game::ScreenWidth,Game::ScreenHeight,BLACK);
    //TODO: Draw Game Title
    float buttonWidth = Game::ScreenWidth/3;
    float buttonHeight = 30;
    float buttonsHPos = Game::ScreenWidth / 2 - buttonWidth/2;
    float buttonsVPos = Game::ScreenHeight / 2;
    float buttonOffset = buttonHeight + 10;
    float onButtonHOffset = 5;
    float onButtonVOffset = 5;
    float buttonFontSize = 20;
    Rectangle ButtonRec = {buttonsHPos, buttonsVPos, buttonWidth, buttonHeight};
    std::string buttonTexts[3] = {"Start Game", "Settings", "Quit"};
    for (int i = 0; i<3;i++){
        DrawRectangle(buttonsHPos, buttonsVPos + buttonOffset * i, buttonWidth, buttonHeight, DARKGRAY);
        DrawText(buttonTexts[i].c_str(), buttonsHPos + onButtonHOffset, buttonsVPos + buttonOffset * i + onButtonVOffset, buttonFontSize, WHITE);
    }
    DrawText(TextFormat("%i",this->menuCursor),0,0,40,WHITE);
    DrawRectangleLinesEx(Rectangle{buttonsHPos, (float) buttonsVPos + buttonOffset * menuCursor, buttonWidth, buttonHeight}, 3, WHITE);
}

void gameClass::drawGamePlay() {
    //TODO Draw Gameplay
}

void gameClass::drawSettings() {
    //TODO Draw Settings
}

void gameClass::drawPause() {
    //TODO DrawPause
}

void gameClass::updateGameplay() {
    //TODO DO THE GAMEPLAY
}

void gameClass::updatePause() {
    //TODO Pause updating
}
