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

    // Player Getter
    Color getPlayer();

    // Player Setter
    void setPlayer(Color player);

protected:
    // The player associated with this command
    Color player;
};

#endif