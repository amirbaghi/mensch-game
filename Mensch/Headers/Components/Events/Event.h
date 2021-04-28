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
    // Player getter
    Color getPlayer();
    // EventType Getter
    EventType getEventType();
    // Dice Number Getter
    int getDiceNum();

    // Player Setter
    void setPlayer(Color player);
    // Actor Setter
    void setActor(Actor* actor);
    // EventType Setter
    void setEventType(EventType eventType);
    // Dice Number Setter
    void setDiceNum(int diceNum);

private:
    // The actor associated with the event
    Actor *actor;
    // The type of event
    EventType event;
    // The Dice Number for which the event has happened
    int diceNum;
    // Player associated with the event
    Color player;
};

#endif