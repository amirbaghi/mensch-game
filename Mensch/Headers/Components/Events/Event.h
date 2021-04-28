#ifndef EVENT_H
#define EVENT_H

#include <vector>
#include "../Actors/Actor.h"
#include "./EventType.h"

class Event
{
public:
    Event();
    ~Event();

    // Actors getter
    std::vector<Actor *> getActors();
    // Player getter
    Color getPlayer();
    // EventType Getter
    EventType getEventType();
    // Dice Number Getter
    int getDiceNum();

    // Player Setter
    void setPlayer(Color player);
    // Actors Setter
    void setActors(std::vector<Actor *> actors);
    // EventType Setter
    void setEventType(EventType eventType);
    // Dice Number Setter
    void setDiceNum(int diceNum);

private:
    // The actors associated with the event
    std::vector<Actor *> actors;
    // The type of event
    EventType event;
    // The Dice Number for which the event has happened
    int diceNum;
    // Player who's caused the event
    Color player;
};

#endif