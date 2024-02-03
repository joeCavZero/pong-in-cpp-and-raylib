#ifndef Game_h
#define Game_h

#include "raylib.h"

class Game
{

public:
    int screen_width;
    int screen_height;
    const char *title;

    Color main_color;
    Color bkg_color;

    Game(int screen_width, int screen_height, const char *title , Color main_color, Color bkg_color);
    ~Game();
    void Start();
    void GameLoop();
    void End();

private:
};

#endif