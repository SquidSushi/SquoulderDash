﻿
#include <cstdlib>
#include <algorithm>

#include "raylib.h"

#include "config.h"
#include "gameClass.h"
#include "myFunctions.h"

gameClass *game;
int globalFrameCounter; //globalFrameCounter
Vector2 vMouse;

int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);
    SetWindowSize(GetScreenWidth() * 2, GetScreenHeight() * 2);
    SetWindowPosition((GetMonitorWidth(GetCurrentMonitor()) - GetScreenWidth()) / 2,
                      (GetMonitorHeight(GetCurrentMonitor()) - GetScreenHeight()) / 2);

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here
    // ...
    // ...
    InitAudioDevice();
    game = new gameClass();
    Texture2D myTexture = LoadTexture("assets/graphics/testimage.png");
    RenderTexture2D canvas = LoadRenderTexture(Game::ScreenWidth, Game::ScreenHeight);
    float renderScale{}; //those two are relevant to drawing and code-cleanliness
    Rectangle renderRec{};
    Music song = LoadMusicStream("assets/audio/song.mp3");
    SetMusicVolume(song, 1);
    float volume; //I use this later on
    PlayMusicStream(song);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        globalFrameCounter++;
        if (IsKeyDown(KEY_LEFT_ALT) && IsKeyPressed(KEY_ENTER)) { //Fullscreen logic.
            if (IsWindowFullscreen()) {
                ToggleFullscreen();
                SetWindowSize(Game::ScreenWidth, Game::ScreenHeight);
            } else {
                SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
                ToggleFullscreen();
            }
        }
        vMouse = GetVmouse(renderScale, renderRec);
        // Updates that are made by frame are coded here
        // ...
        // ...
        game->update();

        if (IsKeyDown(KEY_M)) {
            volume = 0.1;
        } else {
            volume = 1;
        }
        SetMusicVolume(song, volume);
        UpdateMusicStream(song);
        if (vMouse.x < 0 || vMouse.x > Game::ScreenWidth || vMouse.y < 0 || vMouse.y > Game::ScreenHeight) {
            ShowCursor();
        } else {
            HideCursor();
        }

        BeginDrawing();
        // You can draw on the screen between BeginDrawing() and EndDrawing()
        // For the letterbox we draw on canvas instad
        BeginTextureMode(canvas);
        { //Within this block is where we draw our app to the canvas.
            ClearBackground(BLACK);
            DrawRectangleGradientV(0, 0, Game::ScreenWidth, Game::ScreenHeight, ColorFromHSV((float)globalFrameCounter, 1, 1),
                                   ColorFromHSV((float)globalFrameCounter + 180, 1, 1));
            DrawText("Hello, world!", 10, 10, 30, LIGHTGRAY);
            DrawTexture(myTexture, 10, 100, WHITE);
            DrawCircle((int)vMouse.x, (int)vMouse.y, 16.0, GetColor(0xFFFF0000));
            Vector2 tri2 = vMouse;
            tri2.x += 9;
            tri2.y += 18;
            Vector2 tri3 = vMouse;
            tri3.x += 18;
            tri3.y += 9;
            DrawTriangle(vMouse, tri2, tri3, ColorFromHSV((float)globalFrameCounter * 2, 0.5, 1));
            DrawTriangleLines(vMouse, tri2, tri3, BLACK);
        }
        EndTextureMode();
        //The following lines put the canvas in the middle of the window and have the negative as black
        ClearBackground(BLACK);
        renderScale = std::min((float)GetScreenHeight() /
                               (float) canvas.texture.height, //Calculates how big or small the canvas has to be rendered.
                               (float)GetScreenWidth() / (float) canvas.texture.width);
        renderRec.width = (float)canvas.texture.width * renderScale;
        renderRec.height = (float)canvas.texture.height * renderScale;
        renderRec.x = ((float)GetScreenWidth() - renderRec.width) / 2.0f;
        renderRec.y = ((float)GetScreenHeight() - renderRec.height) / 2.0f;
        DrawTexturePro(canvas.texture, Rectangle{0, 0, (float) canvas.texture.width, (float) -canvas.texture.height},
                       renderRec,
                       {}, 0, WHITE);
        EndDrawing();
    } // Main game loop end

    // De-initialization here
    // ...
    // ...
    UnloadTexture(myTexture);

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}


