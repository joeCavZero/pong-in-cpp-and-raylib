#include <iostream>
#include "raylib.h"
#include <cstdlib>

#include "Game.h"

#include "Paddle.h"
#include "Ball.h"
#include "utils/Timer.h"
#include "utils/PointText.h"
#include "utils/Settings.h"





Game::Game(int screen_width, int screen_height, const char *title)
{
    this->screen_width = screen_width;
    this->screen_height = screen_height;
    this->title = title;
}

Game::~Game() {}
Game Game::New(int screen_width, int screen_height, const char *title)
{
    return Game(screen_width, screen_height, title);
}
void Game::Start()
{
    
    
    InitWindow(this->screen_width, this->screen_height, this->title);
    SetTargetFPS(60);

    SetExitKey(KEY_NULL);
    this->GameLoop();

    this->End();
}

void Game::GameLoop()
{   
    //------ LOADING ASSETS ---------------
    Font gameFont = LoadFont("./../assets/fonts/HachicroUndertaleBattleFontRegular-L3zlg.ttf");
    
    RenderTexture2D render_display = LoadRenderTexture( screen_width , screen_height );
    //------ INITIALIZING OBJECTS ---------

    int point1 = 0;
    int point2 = 0;

    Timer timer = Timer::New();
    
    Paddle p1 = Paddle::New(1);
    Paddle p2 = Paddle::New(2);
    PointText point_text_1 = PointText::New(0, {64, 50}, gameFont);
    PointText point_text_2 = PointText::New(0, {screen_width -64, 50}, gameFont);


    Ball ball = Ball::New(
        screen_width / 2 , screen_height / 2, 
        0, 0, 
        screen_width, screen_height);

    //---------------------------

    timer.Start(3.0);

    //------ GAME LOOP ----------
    while (!WindowShouldClose())
    {
        
        if (IsKeyPressed(KEY_F11)){
            ToggleGameFullscreen();
        }

        timer.Update();

        p1.Update();
        p2.Update();
        if( timer.IsFinished() ){
            ball.Update();
        }
        


        //------ CHECA AS COLISÕES
        if (ball.CheckCollisionWithPaddle(p1)){
            ball.motion_x = 1;
            ball.speed += 0.2;
        } else if (ball.CheckCollisionWithPaddle(p2)){
            ball.motion_x = -1;
            ball.speed += 0.2;
        }
        
        //---- SISTEMA DE POINTS E RESET

        if (ball.x <=ball.min_x){
            timer.Start(VOID_TIME);
            ball.Restart();
            point2++;
            point_text_2.SetPoint(point2);
        }
        else if (ball.x >= ball.max_x){
            timer.Start(VOID_TIME);
            ball.Restart();

            point1++;
            point_text_1.SetPoint(point1);
        }

        //------- PARTE DO DRAW (DESENHO) ------------
        BeginTextureMode(render_display);
        ClearBackground(BKG_COLOR);
        p1.Draw();
            p2.Draw();
            ball.Draw();

            point_text_1.Draw();
            point_text_2.Draw();
            
            DrawLineEx(
                {static_cast<float>( screen_width )/2 , 0.0f } ,
                { static_cast<float>( screen_width ) / 2 , static_cast<float>(screen_height) } ,
                3.0,
                MAIN_COLOR);
        EndTextureMode();
        // - - - - - - - 
        BeginDrawing();

        ClearBackground(BKG_COLOR);

        DrawTexturePro(
            render_display.texture,
            {0.0 ,0.0 , static_cast<float>(render_display.texture.width) , static_cast<float>(-render_display.texture.height)},
            {0.0 ,0.0 , static_cast<float>(GetScreenWidth()) , static_cast<float>(GetScreenHeight())},
            {0.0 ,0.0}, 0.0,
            WHITE
        );
            
        EndDrawing();
    }
}

void Game::End()
{
    CloseWindow();
}

void Game::ToggleGameFullscreen()
{
    
    if (IsWindowFullscreen() ){
        ToggleFullscreen();
        SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
        return;
    }else {
        int monitor = GetCurrentMonitor();
        
        SetWindowSize(GetMonitorWidth(monitor),GetMonitorHeight(monitor));
        ToggleFullscreen();
    }
    
}