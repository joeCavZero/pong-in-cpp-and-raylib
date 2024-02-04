#ifndef Game_h
#define Game_h

#include "raylib.h"

class Game
{

public:
    int screen_width;
    int screen_height;
    const char *title;

    Game(int screen_width, int screen_height, const char *title);
    ~Game();
    static Game New(int screen_width, int screen_height, const char *title);
    void Start();
    void GameLoop();
    void End();
    void ToggleGameFullscreen();

private:
};

#endif