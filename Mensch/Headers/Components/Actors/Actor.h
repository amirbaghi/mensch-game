#ifndef ACTOR_H
#define ACTOR_H

#include "../Observer.h"
#include "../Color.h"
#include "../Model/Model.h"

class Actor : public Observer
{
public:
    Actor(Model *model);
    virtual ~Actor();

    // Abstract Render Method
    virtual void render() = 0;

    // Abstract Color Getter
    virtual Color getColor() = 0;

protected:
    // Actor's Model
    Model *model;
};

#endif