#include "./Headers/Game.h"

int main(int argc, char** argv)
{
    Game* game = Game::instance();

    game->run();

    return 0;
}