#ifndef Ball_h
#define Ball_h

#include "Ball.h"
#include "raylib.h"

class Ball{
    private:
        void Input();

    public:
        float x , y;
        float radius;
        float motion_x , motion_y;
        Color color;

        Ball(float x , float y);

        void Update();
        void Draw();

        void Movement();
        void BounceX();
        void BounceY();

        
};

#endif