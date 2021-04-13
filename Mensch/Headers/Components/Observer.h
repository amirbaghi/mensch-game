#ifndef OBSERVER_H
#define OBSERVER_H

#include "./Subject.h"
#include "./Events/Event.h"
#include "./Actors/Actor.h"

class Observer
{
public:
    virtual ~Observer(){};

    // On Notify Method, which should be implemented for each observer
    virtual void onNotify(Event& event) = 0;
};

#endif