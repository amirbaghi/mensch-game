#include "./Headers/Components/UI/UIEngine.h"
#include "./Headers/Game.h"


UIEngine::UIEngine()
{
}

UIEngine::UIEngine(Game *game)
{
    this->game = game;
}

UIEngine::~UIEngine()
{
}

UIEngine *UIEngine::instance(Game *game)
{
    static UIEngine *instance = new UIEngine(game);
    return instance;
}

void UIEngine::renderUI()
{
    // Render UI Here
}