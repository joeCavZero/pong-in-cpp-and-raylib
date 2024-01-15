#ifndef Paddle_h
#define Paddle_h

#include "raylib.h"

class Paddle{
    public:
        float x , y;
        float width , height;
        float speed;

        Color color;

        Paddle(float x , float y , Color color);

        void Update();
        void Draw();

        void Movement();
        
        
};

#endif