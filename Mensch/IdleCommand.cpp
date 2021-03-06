#include "./Headers/Components/Command/IdleCommand.h"
#include <iostream>

IdleCommand::IdleCommand()
{
}

IdleCommand::~IdleCommand()
{
}

int IdleCommand::getDiceNum()
{
    return this->diceNum;
}

void IdleCommand::setDiceNum(int diceNum)
{
    this->diceNum = diceNum;
}

Event *IdleCommand::execute(bool shouldLog)
{
    // Nothing should be done
    Event *e = new Event();

    e->setPlayer(this->player);
    e->setDiceNum(this->diceNum);
    e->setEventType(EVENT_NO_MOVE);

    return e;
}