#ifndef EVENT_H
#define EVENT_H

#include "../Actors/Actor.h"
#include "./EventType.h"

class Event
{
public:
    Event();
    ~Event();

    // Actor getter
    Actor* getActor();
    // EventType Getter
    EventType getEventType();

    // Actor Setter
    void setActor(Actor* actor);
    // EventType Setter
    void setEventType(EventType eventType);

private:
    // The actor associated with the event
    Actor *actor;
    // The type of event
    EventType event;
};

#endif