#include <iostream>
#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"
#include <math.h>


Ball::Ball(float x , float y , float min_x , float min_y , float max_x , float max_y , float radius , Color color){
    this->x = x;
    this->y = y;
    this->radius = radius;

    this->speed = 2.0;
    this->motion_x = 1;
    this->motion_y = 1;

    this->color = color;

    this->min_x = min_x;
    this->min_y = min_y;

    this->max_x = max_x;
    this->max_y = max_y;
}

Ball Ball::New(float x, float y , float min_x , float min_y , float max_x , float max_y ){
    
    return Ball( x , y, min_x , min_y , max_x , max_y , 10.0 , WHITE);
}

void Ball::Movement(){
    CheckCollisionAtY();

    this->x += this->motion_x * this->speed;
    this->y += this->motion_y * this->speed;
}

bool Ball::CheckCollisionWithPaddle(Paddle p){

    bool isColliding = CheckCollisionRecs(
        Rectangle{
            (this->x - this->radius) , (this->y - this->radius) ,
            (this->radius*2) , (this->radius*2) } ,
        Rectangle{
            (p.x) , (p.y) ,
            (p.width) , (p.height) }
    );

    return isColliding;
    return false;
}

void Ball::CheckCollisionAtY()
{
    if (this->y + this->radius >= this->max_y)
    {
        
        this->motion_y = -1;
    }
    else if (this->y - this->radius <= this->min_x)
    {
        

        this->motion_y = 1;
    }
}
void Ball::Restart(){
    this->x = this->max_x / 2;
    this->y = this->max_y /2;
    this->speed = 2.0;
}
//--------------------------------------------------------------

void Ball::Update(){
    this->Movement();
}
void Ball::Draw(){
    DrawCircle(x,y,radius,color);
}