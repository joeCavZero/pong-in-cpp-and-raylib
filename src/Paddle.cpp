#include "Paddle.h"
#include "raylib.h"

#include <iostream>
#include <math.h>

#define PADDLE_WIDTH 20.0
#define PADDLE_HEIGHT 100.0

Paddle::Paddle(int player_number, float x, float y, Color color , float max_x , float max_y)
{   
    this->player_number = player_number;
    this->x = x;
    this->y = y;
    this->width = PADDLE_WIDTH;
    this->height = PADDLE_HEIGHT;
    this->speed = 10.0;
    this->color = color;

    this->max_x = max_x;
    this->max_y = max_y;
}

void Paddle::Movement()
{
    //Input e movimento para os players 1 e 2
    //----Caso for o player 1 (esquerdo)
    if ( this->player_number == 1 ) {
        if (IsKeyDown(KEY_W))
        {
            this->y -= this->speed;
        }
        else if (IsKeyDown(KEY_S))
        {
            this->y += this->speed;
        }
    }
    
    //----Caso for o player 2 (direito)
    else if ( this->player_number == 2) {
        if ( IsKeyDown(KEY_UP) )
        {
            this->y -= this->speed;
        }
        else if ( IsKeyDown(KEY_DOWN) )
        {
            this->y += this->speed;
        }
    }
    // - - - - - - - - - - - - - - - - - - - - - -
    // faz como se fosse um clamp, como se fosse um "teto" e "chão"
    if (this->y < 0){
        this->y = 0;
    }else if (this->y +this->height > this->max_y){
        this->y = this->max_y - this->height;
    }
}

void Paddle::Update()
{
    this->Movement();
}

void Paddle::Draw()
{

    DrawRectangle(
        this->x, 
        this->y, 
        this->width , 
        this->height , 
        this->color) ;
}


Paddle Paddle::New(int player_type){

    if ( player_type == 1 ){
        return Paddle(
            1,
            0.0 , GetScreenHeight()/2,
            WHITE,
            GetScreenWidth(),
            GetScreenHeight()
        );
    } else{
        return Paddle(
            2,
            GetScreenWidth() - PADDLE_WIDTH , GetScreenHeight()/2 ,
            WHITE,
            GetScreenWidth(),
            GetScreenHeight()
        );
    }

}