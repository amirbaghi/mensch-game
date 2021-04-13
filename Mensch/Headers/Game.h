#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <chrono>
#include "./Components/Actors/Piece.h"
#include "./Components/Actors/Board.h"
#include "./Components/AI/AIEngine.h"
#include "./Components/Render/RenderEngine.h"
#include "./Components/Physics/PhsyicsEngine.h"
#include "./Components/Command/CommandStream.h"
#include "./Components/UI/UIEngine.h"
#include "./Components/Spawner/BoardSpawner.h"
#include "./Components/Spawner/PieceSpawner.h"

class Game
{
public:
    ~Game();

    // Board Getter
    Board *getBoard();

    // Piece Getter
    std::vector<Piece *> getPieces();

    // Current Turn Getter
    Color getCurrentTurn();

    // Current Turn Setter
    void setCurrentTurn(Color currentTurn);

    // Go Next Turn
    void nextTurn();

    // Instance Method
    static Game *instance();

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

    // Board Spawner
    BoardSpawner *boardSpawner;

    // Piece Spawner
    PieceSpawner *pieceSpawner;

    // Board
    Board *board;

    // Pieces
    std::vector<Piece *> pieces;

    // Start Time
    clock_t startTime;

    // Current Turn
    Color currentTurn;
};

#endif