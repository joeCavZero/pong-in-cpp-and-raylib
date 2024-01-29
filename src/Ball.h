#ifndef Ball_h
#define Ball_h

#include <iostream>
#include "Ball.h"
#include "raylib.h"
#include "Paddle.h"

class Ball{
    private:
        void Input();

    public:
        float x , y;
        float radius;

        float speed;
        float motion_x , motion_y;

        float min_x, min_y;
        float max_x, max_y;

        Color color;

        Ball(float x , float y, float min_x , float min_y , float max_x , float max_y , float radius , Color color);
        static Ball New(float x , float y, float min_x , float min_y , float max_x , float max_y );
        
        void Update();
        void Draw();

        void Movement();
        bool CheckCollisionWithPaddle(Paddle paddle);
        void CheckCollisionAtY();

        
};

#endif