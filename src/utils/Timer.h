
#ifndef Timer_h
#define Timer_h

#include "raylib.h"

class Timer {
    public:
        float life_time;
    
    Timer();
    static Timer New();

    void Start(float life_time);
    void Update();
    bool IsFinished();
    



};

#endif