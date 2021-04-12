#ifndef SPAWNER_H
#define SPAWNER_H

#include "../Actors/Actor.h"

class Spawner
{
public:
    Spawner();
    virtual ~Spawner();

    // Abstract method for spawning actors
    virtual Actor *spawnActor() = 0;
};

#endif