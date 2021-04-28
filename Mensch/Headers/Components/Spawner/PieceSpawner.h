#ifndef PIECESPAWNER_H
#define PIECESPAWNER_H

#include "./Spawner.h"
#include "../Color.h"
#include "../Actors/Piece.h"
#include "../Model/PieceModel.h"

class PieceSpawner : public Spawner
{
public:
    PieceSpawner(PieceModel *model);
    ~PieceSpawner();

    // Spawn Color Getter
    Color getSpawnColor();

    // Spawn Color Setter
    void setSpawnColor(Color spawnColor);

    // Piece Spawner
    Piece *spawn();

private:
    
    // Spawning Color (Should be set before spawning)
    Color spawnColor;
};

#endif