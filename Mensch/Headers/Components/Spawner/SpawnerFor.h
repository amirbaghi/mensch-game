#ifndef SPAWNERFOR_H
#define SPAWNERFOR_H

#include "./Spawner.h"
#include "../Actors/Actor.h"
#include "../Model/Model.h"

template <class T>
class SpawnerFor : public Spawner
{
public:
    SpawnerFor(Model *model);
    ~SpawnerFor();

    // Method for spawning actors
    Actor *spawnActor();

private:
    // Model for the specified actor
    Model *model;
};

#endif