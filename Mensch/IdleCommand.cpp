#include "./Headers/Components/Command/IdleCommand.h"
#include <iostream>

IdleCommand::IdleCommand()
{
}

IdleCommand::~IdleCommand()
{
}

Event *IdleCommand::execute()
{


    // Nothing should be done
    Event *e = new Event();

    e->setActor(nullptr);
    e->setEventType(EVENT_NO_MOVE);

    return e;
}