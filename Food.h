#pragma once
#include <deque>
#include <raylib.h>

class Food {
public:
    Vector2 position;
    Texture2D texture;

    Food(std::deque<Vector2> snakeBody);
    ~Food();
    void Draw();
    Vector2 GenerateRandomPos(const std::deque<Vector2>& snakeBody);

private:
    Vector2 GenerateRandomCell();
};
#pragma once
