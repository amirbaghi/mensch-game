#ifndef PIECESPAWNER_H
#define PIECESPAWNER_H

#include "./Spawner.h"
#include "../Actors/Piece.h"
#include "../Model/PieceModel.h"

class PieceSpawner : public Spawner
{
public:
    PieceSpawner(PieceModel *model);
    ~PieceSpawner();

    // Piece Spawner
    Piece *spawn();
};

#endif