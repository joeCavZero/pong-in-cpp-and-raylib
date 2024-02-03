#ifndef Text_h
#define Text_h

#include "raylib.h"

class PointText{
    
    private:
        int point;
        Vector2 position;
        Font font;
    public:
    PointText(int point, Vector2 position, Font font);
    static PointText New(int point, Vector2 position , Font font);

    //void Update();
    void Draw();
    void SetPoint(int point);

};

#endif