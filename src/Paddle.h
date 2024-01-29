#ifndef Paddle_h
#define Paddle_h

#include "raylib.h"

class Paddle{
    public:
        float x , y;
        float width , height;
        float speed;

        float max_x , max_y;

        int player_number;

        Color color;

        Paddle(int player_number,float x , float y , Color color , float max_x , float max_y );

        static Paddle New(int player_type);

        void Update();
        void Draw();

        void Movement();
        
        
};

#endif