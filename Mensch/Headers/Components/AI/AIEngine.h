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
    static AIEngine &instance(Game *game);

    // Generate Move
    Command *generateMove();

private:
    // Private Constructors
    AIEngine();
    AIEngine(Game *game);

    // Current Turn
    Color currentTurn;

    // Game Object
    Game *game;
};

#endif