#include "./Headers/Components/Command/Command.h"

Command::Command()
{

}

Command::~Command()
{
    
}

Color Command::getPlayer()
{
    return this->player;
}

void Command::setPlayer(Color player)
{
    this->player = player;
}
