#include <iostream>
#include "raylib.h"

#include "Game.h"

#include "utils/settings.h"

int main(void) {
    

    Game game = Game::New( SCREEN_WIDTH , SCREEN_HEIGHT , "pong");

    game.Start();



    return 0;
}
