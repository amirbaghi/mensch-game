#include <iostream>
#include <fstream>
#include "./Headers/Components/Accounting/AccountingEngine.h"

AccountingEngine::AccountingEngine()
{
}

AccountingEngine::~AccountingEngine()
{
}

AccountingEngine *AccountingEngine::instance()
{
    static AccountingEngine *instance = new AccountingEngine();
    return instance;
}

void AccountingEngine::initAccounting()
{
    // Initializing the counters for all players as 0

    redWaitDuration = 0;
    blueWaitDuration = 0;
    greenWaitDuration = 0;
    yellowWaitDuration = 0;

    redGainedScore = 0;
    blueGainedScore = 0;
    greenGainedScore = 0;
    yellowGainedScore = 0;

    redLostScore = 0;
    blueLostScore = 0;
    greenLostScore = 0;
    yellowLostScore = 0;

    redNumberOfStarts = 0;
    blueNumberOfStarts = 0;
    greenNumberOfStarts = 0;
    yellowNumberOfStarts = 0;

    redCoveredDistance = 0;
    blueCoveredDistance = 0;
    greenCoveredDistance = 0;
    yellowCoveredDistance = 0;
}

void AccountingEngine::writeOut(time_t time)
{
    std::cout << (float)time / CLOCKS_PER_SEC << " " << redWaitDuration << " " << blueWaitDuration << " " << greenWaitDuration << " " << yellowWaitDuration << std::endl;
}

void AccountingEngine::onNotify(Event &event)
{
    EventType eventType = event.getEventType();
    Color playerColor = event.getPlayer();

    switch (playerColor)
    {
    case RED:
        if (eventType == EVENT_NO_MOVE || eventType == EVENT_NO_MOVE_SIX)
        {
            redWaitDuration += 1;
        }
        break;
    case BLUE:
        if (eventType == EVENT_NO_MOVE || eventType == EVENT_NO_MOVE_SIX)
        {
            blueWaitDuration += 1;
        }
        break;
    case GREEN:
        if (eventType == EVENT_NO_MOVE || eventType == EVENT_NO_MOVE_SIX)
        {
            greenWaitDuration += 1;
        }
        break;
    case YELLOW:
        if (eventType == EVENT_NO_MOVE || eventType == EVENT_NO_MOVE_SIX)
        {
            yellowWaitDuration += 1;
        }
        break;
    default:
        break;
    }
}