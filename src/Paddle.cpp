#include "Paddle.h"
#include "raylib.h"

#include <iostream>

Paddle::Paddle(float x, float y, Color color)
{
    this->x = x;
    this->y = y;
    this->width = 12;
    this->height = 32;
    this->speed = 10.0;
    this->color = color;
}

void Paddle::Movement()
{

    if (IsKeyDown(KEY_W))
    {
        this->y -= this->speed;
    }
    else if (IsKeyDown(KEY_S))
    {
        this->y += this->speed;
    }
}

void Paddle::Update()
{
    this->Movement();
}

void Paddle::Draw()
{

    DrawRectangle(
        this->x + (this->width/2) , 
        this->y + (this->height/2) , 
        this->width , 
        this->height , 
        this->color) ;
}