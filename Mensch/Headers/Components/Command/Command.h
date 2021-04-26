#ifndef COMMAND_H
#define COMMAND_H

#include "../Events/Event.h"

class Command
{
public:
    Command();
    virtual ~Command();

    // Execute command for each command
    virtual Event* execute(bool shouldLog) = 0;
};

#endif