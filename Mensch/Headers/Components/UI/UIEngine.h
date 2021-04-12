#ifndef UIENGINE_H
#define UIENGINE_H

#include "../../Game.h"

class UIEngine
{
public:
    ~UIEngine();

    // Instance Method
    static UIEngine &instance(Game *game);

    // Method to render UI
    void renderUI();

private:
    // Private Constructor
    UIEngine(Game *game);
};

#endif