#include "Snake.h"

extern int cellSize;
extern Color darkGreen;

Snake::Snake() {
    body = { {6,9}, {5,9}, {4,9} };
    direction = { 1,0 };
    addSegment = false;
}

void Snake::Draw() {
    for (auto& segment : body) {
        Rectangle rect = { segment.x * cellSize, segment.y * cellSize, (float)cellSize, (float)cellSize };
        DrawRectangleRounded(rect, 0.5, 6, darkGreen);
    }
}

void Snake::Update() {
    body.push_front(Vector2Add(body[0], direction));
    if (!addSegment) body.pop_back();
    else addSegment = false;
}

void Snake::Reset() {
    body = { {6,9}, {5,9}, {4,9} };
    direction = { 1,0 };
}
