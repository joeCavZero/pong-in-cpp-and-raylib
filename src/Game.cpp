#include <iostream>
#include "raylib.h"

#include "Game.h"

#include "Paddle.h"
#include "Ball.h"

#define MAIN_COLOR = WHITE
#define BKG_COLOR = BLACK


Game::Game(int screen_width, int screen_height, const char *title, Color main_color, Color bkg_color)
{
    this->screen_width = screen_width;
    this->screen_height = screen_height;
    this->title = title;
    this->main_color = main_color;
    this->bkg_color = bkg_color
}

Game::~Game() {}
void Game::InitGame()
{
    InitWindow(this->screen_width, this->screen_height, this->title);
    SetTargetFPS(60);
}

void Game::GameLoop()
{

    Paddle p1 = Paddle(
        4.0,
        this->screen_height/2,
        MAIN_COLOR);

    Paddle p2 = Paddle(
        screen_width - 4.0,
        screen_height/2,
        MAIN_COLOR
    );

    Ball ball = Ball(
        screen_width/2,
        screen_height/2
    );
    while (!WindowShouldClose())
    {

        p1.Update();

        BeginDrawing();

        ClearBackground(BLACK);
        p1.Draw();
        DrawText("kkKKKKKK de primeira", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }
}

void Game::EndGame()
{
    CloseWindow();
}