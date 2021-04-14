#include "./Headers/Components/Spawner/PieceSpawner.h"

PieceSpawner::PieceSpawner(PieceModel *model) : Spawner(model)
{
}

PieceSpawner::~PieceSpawner()
{
}

Color PieceSpawner::getSpawnColor()
{
    return this->spawnColor;
}

void PieceSpawner::setSpawnColor(Color spawnColor)
{
    this->spawnColor = spawnColor;
}

Piece *PieceSpawner::spawn()
{
    // Spawning a new piece
    Piece *p = new Piece(this->model);

    // Setting the color and current square for the square
    p->setCurrentSquare(nullptr);
    p->setPieceColor(this->spawnColor);
    p->setHasPassedHomeSquare(false);

    return p;
}
