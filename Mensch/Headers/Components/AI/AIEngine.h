#ifndef AIENGINE_H
#define AIENGINE_H

#include "../Command/Command.h"
#include "../../Game.h"
#include "../Color.h"

class AIEngine
{
public:
    ~AIEngine();

    // Instance Method
    static AIEngine *instance(Game *game);

    // Generate Move
    Command *generateMove(Color player);

private:
    // Private Constructors
    AIEngine();
    AIEngine(Game *game);

    // Game Object
    Game *game;
};

#endif