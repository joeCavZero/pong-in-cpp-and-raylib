#include <iostream>
#include "raylib.h"

#include "Game.h"


int main(void) {
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 450;

    Game game = Game(SCREEN_WIDTH , SCREEN_HEIGHT , "K" , WHITE , BLACK);

    game.InitGame();
    game.GameLoop();
    game.EndGame();
    

    return 0;
}