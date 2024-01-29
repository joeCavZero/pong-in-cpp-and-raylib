#include <iostream>
#include "raylib.h"

#include "Game.h"

#include "Paddle.h"
#include "Ball.h"

#define MAIN_COLOR WHITE
#define BKG_COLOR BLACK


Game::Game(int screen_width, int screen_height, const char *title, Color main_color, Color bkg_color)
{
    this->screen_width = screen_width;
    this->screen_height = screen_height;
    this->title = title;
    this->main_color = main_color;
    this->bkg_color = bkg_color;
}

Game::~Game() {}
void Game::InitGame()
{
    InitWindow(this->screen_width, this->screen_height, this->title);
    SetTargetFPS(60);
}

void Game::GameLoop()
{

    Paddle p1 = Paddle::New(1);
    Paddle p2 = Paddle::New(2);

    Ball ball = Ball::New(
        screen_width / 2 , screen_height / 2, 
        0, 0, 
        screen_width, screen_height);

    //-----------

    Font gameFont = LoadFont("./../assets/fonts/HachicroUndertaleBattleFontRegular-L3zlg.ttf");

    //------ LOOP
    while (!WindowShouldClose())
    {

        p1.Update();
        p2.Update();
        ball.Update();


        //checa se bateu no paddle
        if (ball.CheckCollisionWithPaddle(p1)){
            std::cout << "Bateu no p1 kkkkk\n";
            ball.motion_x = 1;
        } else if (ball.CheckCollisionWithPaddle(p2)){
            ball.motion_x = -1;
        }
        
        BeginDrawing();

        ClearBackground(BLACK);

            p1.Draw();
            p2.Draw();
            ball.Draw();

            
            DrawTextEx(gameFont,
                "teste", 
                {100,100}, 
                90.0,1.0,
                WHITE);
            DrawLineEx(
                {this->screen_width/2 , 0 } ,
                { this->screen_width/2 ,this->screen_height } ,
                3.0,
                WHITE);
        EndDrawing();
    }
}

void Game::EndGame()
{
    CloseWindow();
}