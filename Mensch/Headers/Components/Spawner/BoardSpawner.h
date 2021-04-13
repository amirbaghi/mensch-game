#ifndef BOARDSPAWNER_H
#define BOARDSPAWNER_H

#include "./Spawner.h"
#include "../Actors/Board.h"
#include "../Model/BoardModel.h"
#include "../Model/SquareModel.h"


class BoardSpawner : public Spawner
{
public:
    BoardSpawner(BoardModel *model, SquareModel* squareModel);
    ~BoardSpawner();

    // Board Spawner
    Board *spawn();

private:
    // Square Model
    SquareModel* squareModel;
};

#endif