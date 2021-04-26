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

    // Notify all the observers of the event that happened
    notify((*event));

    // Go to next turn (Only if the move wasn't a 6)
    if (event->getEventType() != EVENT_PIECE_MOVED_SIX && event->getEventType() != EVENT_NO_MOVE_SIX)
    {
        this->game->nextTurn();
    }

    // Delete the event
    delete event;
}
