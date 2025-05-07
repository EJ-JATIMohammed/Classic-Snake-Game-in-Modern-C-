#pragma once
#include <deque>
#include <raylib.h>
#include <raymath.h>

class Snake {
public:
    std::deque<Vector2> body;
    Vector2 direction;
    bool addSegment;

    Snake();
    void Draw();
    void Update();
    void Reset();
};
