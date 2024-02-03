#include "Timer.h"
#include "raylib.h"
#include "raymath.h"

Timer::Timer(){}
Timer Timer::New(){
    return Timer();
}

void Timer::Start(float life_time) {
    this->life_time = life_time;
}

void Timer::Update(){
    if (this->life_time > 0){
        this->life_time -= GetFrameTime();
    }
}


bool Timer::IsFinished(){
    if (this->life_time <= 0){
        return true;
    }
    return false;
}