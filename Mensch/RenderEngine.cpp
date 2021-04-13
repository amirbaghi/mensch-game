#include "./Headers/Components/Render/RenderEngine.h"

RenderEngine::RenderEngine()
{
}

RenderEngine::RenderEngine(Game *game)
{
    this->game = game;
}

RenderEngine::~RenderEngine()
{
}

RenderEngine *RenderEngine::instance(Game *game)
{
    static RenderEngine *instance = new RenderEngine(game);
    return instance;
}

void RenderEngine::render()
{
    // Render Logic Template

    // Render Board
    game->getBoard()->render();

    // Render Pieces
    for (Piece *p : game->getPieces())
    {
        p->render();
    }
}