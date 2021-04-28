#ifndef SPAWNER_H
#define SPAWNER_H

#include "../Actors/Actor.h"
#include "../Model/Model.h"

class Spawner
{
public:
    Spawner(Model *model);
    virtual ~Spawner();

    // Abstract method for spawning
    virtual Actor *spawn() = 0;

protected:
    // The Model Associated with the class for this spawner
    Model *model;
};

#endif