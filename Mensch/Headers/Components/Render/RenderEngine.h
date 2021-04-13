#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include "../../Game.h"

class RenderEngine
{
public:
    ~RenderEngine();

    // Instance Method
    static RenderEngine *instance(Game *game);

    // Method to for rendering
    void render();

private:
    // Private Constructors
    RenderEngine();
    RenderEngine(Game *game);

    // Game Object
    Game *game;
};

#endif