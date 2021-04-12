#ifndef OBSERVER_H
#define OBSERVER_H

#include "./Subject.h"
#include "./Events/Event.h"
#include "./Actors/Actor.h"

class Observer
{
    friend class Subject;

public:
    virtual ~Observer();
    // On Notify Method, which should be implemented for each observer
    virtual void onNotify(Event event, const Actor &actor) = 0;
};

#endif