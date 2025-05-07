#include <raylib.h>
#include "Game.h"

int cellSize = 20;
int cellcount = 25;
Color green = { 173,204,96,255 };
Color darkGreen = { 43,51,24,255 };
double lastUpdateTime = 0;

bool eventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main() {
    InitWindow(cellSize * cellcount, cellSize * cellcount, "Snake Game");
    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(green);

        if (eventTriggered(0.2)) game.Update();

        if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1) { game.snake.direction = { 0, -1 }; game.running = true; }
        if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1) { game.snake.direction = { 0, 1 }; game.running = true; }
        if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1) { game.snake.direction = { -1, 0 }; game.running = true; }
        if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1) { game.snake.direction = { 1, 0 }; game.running = true; }

        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
