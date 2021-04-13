#ifndef OBSERVER_H
#define OBSERVER_H

// #include "./Events/Event.h"

class Event;

class Observer
{
public:
    virtual ~Observer();

    // On Notify Method, which should be implemented for each observer
    virtual void onNotify(Event& event) = 0;
};

#endif