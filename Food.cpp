#include "Food.h"

extern int cellcount;
extern int cellSize;

bool ElementInDeque(Vector2 element, const std::deque<Vector2>& deque) {
    for (const auto& item : deque)
        if (Vector2Equals(item, element)) return true;
    return false;
}

Food::Food(std::deque<Vector2> snakeBody) {
    Image image = LoadImage("image/food.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    position = GenerateRandomPos(snakeBody);
}

Food::~Food() {
    UnloadTexture(texture);
}

void Food::Draw() {
    DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
}

Vector2 Food::GenerateRandomCell() {
    return { (float)GetRandomValue(0, cellcount - 1), (float)GetRandomValue(0, cellcount - 1) };
}

Vector2 Food::GenerateRandomPos(const std::deque<Vector2>& snakeBody) {
    Vector2 pos;
    do {
        pos = GenerateRandomCell();
    } while (ElementInDeque(pos, snakeBody));
    return pos;
}
