#include <iostream>
#include "raylib.h"
#include "Ball.h"

Ball::Ball(float x , float y){
    this->x = x;
    this->y = y;
    this->radius = 5.0;

    this->motion_x = 1;
    this->motion_y = 1;

    this->color = WHITE;
}


void Ball::Movement(){
    this->x += this->motion_x;
    this->y += this->motion_y;
}
void Ball::BounceX(){
    this->motion_x *= -1;
}
void Ball::BounceY(){
    this->motion_y *= -1;
}
void Ball::Update(){
    this->Movement();
}
void Ball::Draw(){
    DrawCircle(x,y,radius,color);
}
