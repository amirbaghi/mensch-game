#ifndef UIENGINE_H
#define UIENGINE_H

class Game;

class UIEngine
{
public:
    ~UIEngine();

    // Instance Method
    static UIEngine *instance(Game *game);

    // Method to render UI
    void renderUI();

private:
    // Private Constructors
    UIEngine();
    UIEngine(Game *game);

    // Game Object
    Game* game;
};

#endif