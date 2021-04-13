#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <chrono>
#include "./Components/AI/AIEngine.h"
#include "./Components/Render/RenderEngine.h"
#include "./Components/Physics/PhsyicsEngine.h"
#include "./Components/Command/CommandStream.h"
#include "./Components/UI/UIEngine.h"
#include "./Components/Spawner/Spawner.h"
#include "./Components/Actors/Board.h"
#include "./Components/Actors/Piece.h"

class Game
{
public:
    ~Game();

    // Instance Method
    static Game &instance();

    // Game initialization
    void initGame();

    // Game Main Loop
    void mainLoop();

private:
    // Private Constructor
    Game();

    // AI Engine
    AIEngine *aiEngine;

    // Render Engine
    RenderEngine *renderEngine;

    // Command Stream
    CommandStream *commandStream;

    // UI Engine
    UIEngine *uiEngine;

    // Physics Engine
    PhysicsEngine *physicsEngine;

    // Square Spawner
    Spawner *squareSpawner;

    // Piece Spawner
    Spawner *pieceSpawner;

    // Board
    Board *board;

    // Pieces
    std::vector<Piece *> pieces;

    // Start Time
    clock_t startTime;
};

#endif