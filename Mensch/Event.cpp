#include "./Headers/Components/Events/Event.h"

Event::Event()
{
}

Event::~Event()
{
}

std::vector<Actor *> Event::getActors()
{
    return this->actors;
}

Color Event::getPlayer()
{
    return this->player;
}

EventType Event::getEventType()
{
    return this->event;
}

int Event::getDiceNum()
{
    return this->diceNum;
}

void Event::setPlayer(Color player)
{
    this->player = player;
}

void Event::setDiceNum(int diceNum)
{
    this->diceNum = diceNum;
}

void Event::setActors(std::vector<Actor *> actors)
{
    this->actors = actors;
}

void Event::setEventType(EventType eventType)
{
    this->event = eventType;
}