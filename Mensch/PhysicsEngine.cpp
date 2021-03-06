#include <unistd.h>
#include "./Headers/Components/Physics/PhsyicsEngine.h"
#include "./Headers/Components/Events/Event.h"
#include "./Headers/Game.h"

PhysicsEngine::PhysicsEngine()
{
}

PhysicsEngine::PhysicsEngine(Game *game)
{
    this->game = game;
}

PhysicsEngine::~PhysicsEngine()
{
}

PhysicsEngine *PhysicsEngine::instance(Game *game)
{
    static PhysicsEngine *instance = new PhysicsEngine(game);
    return instance;
}

void PhysicsEngine::update(Command &command)
{
    // Execute the command
    bool shouldLog = (game->getExecutionMode() == SINGLE_RUN) ? true : false;
    Event *event = command.execute(shouldLog);

    // Simulate Time
    usleep(10 * 1000);

    // Notify all the observers of the event that happened
    notify((*event));

    // Go to next turn (Only if the dice number wasn't a 6)
    if (event->getDiceNum() != 6)
    {
        this->game->nextTurn();
    }

    // Delete the event
    delete event;
}
