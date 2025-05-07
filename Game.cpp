#include "Game.h"

extern int cellcount;

Game::Game() : food(snake.body) {
    running = true;
}

void Game::Draw() {
    food.Draw();
    snake.Draw();
}

void Game::Update() {
    if (running) {
        snake.Update();
        CheckCollisionWithFood();
        CheckCollisionWithEdges();
    }
}

void Game::CheckCollisionWithFood() {
    if (Vector2Equals(snake.body[0], food.position)) {
        snake.addSegment = true;
        food.position = food.GenerateRandomPos(snake.body);
    }
}

void Game::CheckCollisionWithEdges() {
    Vector2 head = snake.body[0];
    if (head.x < 0 || head.x >= cellcount || head.y < 0 || head.y >= cellcount)
        GameOver();
}

void Game::GameOver() {
    snake.Reset();
    food.position = food.GenerateRandomPos(snake.body);
    running = false;
}
