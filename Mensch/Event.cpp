#include "./Headers/Components/Events/Event.h"

Event::Event()
{
}

Event::~Event()
{
}

Actor *Event::getActor()
{
    return this->actor;
}

Color Event::getPlayer()
{
    return this->player;
}

void Event::setPlayer(Color player)
{
    this->player = player;
}

EventType Event::getEventType()
{
    return this->event;
}

void Event::setActor(Actor *actor)
{
    this->actor = actor;
}

void Event::setEventType(EventType eventType)
{
    this->event = eventType;
}