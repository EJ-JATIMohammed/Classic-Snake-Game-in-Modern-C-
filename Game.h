#pragma once
#include "Snake.h"
#include "Food.h"

class Game {
public:
    Snake snake;
    Food food;
    bool running;

    Game();
    void Draw();
    void Update();
    void GameOver();

private:
    void CheckCollisionWithFood();
    void CheckCollisionWithEdges();
};
