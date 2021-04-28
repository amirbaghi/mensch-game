#ifndef IDLECOMMAND_H
#define IDLECOMMAND_H

#include "./Command.h"

class IdleCommand : public Command
{
public:
    IdleCommand();
    ~IdleCommand();

    // Get dice number
    int getDiceNum();

    // Set dice number
    void setDiceNum(int diceNum);

    // Execute command
    Event* execute(bool shouldLog);

private:
    // Dice Number for this idle move
    int diceNum;
};

#endif