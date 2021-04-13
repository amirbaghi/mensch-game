#ifndef BOARDSPAWNER_H
#define BOARDSPAWNER_H

#include "./Spawner.h"
#include "../Actors/Board.h"
#include "../Model/BoardModel.h"

class BoardSpawner : public Spawner
{
public:
    BoardSpawner(BoardModel *model);
    ~BoardSpawner();

    // Board Spawner
    Board *spawn();
};

#endif