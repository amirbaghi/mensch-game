#include "./Headers/Game.h"

int main(int argc, char** argv)
{
    Game* game = Game::instance();

    game->initGame();

    game->mainLoop();

    return 0;
}