#include <iostream>

#include "raylib.h"
#include "PointText.h"
#include "settings.h"
#include "string.h"

PointText::PointText(int point , Vector2 position, Font font){
    this->point = point;
    this->position = position;
    this->font = font;
};

PointText PointText::New(int point, Vector2 position, Font font){
    return PointText(point, position, font);
}

void PointText::Draw(){
    DrawTextEx(
        this->font,
        std::to_string(this->point).c_str(),
        this->position,
        TEXT_SIZE,
        TEXT_SPACING,
        MAIN_COLOR

    );
}

void PointText::SetPoint(int point){
    this->point = point;
    
}