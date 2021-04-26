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
    // Delete the previous stats file (If exists)
    std::remove("stats.txt");

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

    std::ofstream f;
    f.open("stats.txt", std::ios::out | std::ios::app);
    f << (float)time / CLOCKS_PER_SEC << " " << redWaitDuration << "/" << redGainedScore << "/" << redLostScore << "/" << redNumberOfStarts << " "
      << blueWaitDuration << "/" << blueGainedScore << "/" << blueLostScore << "/" << blueNumberOfStarts << " "
      << greenWaitDuration << "/" << greenGainedScore << "/" << greenLostScore << "/" << greenNumberOfStarts << " "
      << yellowWaitDuration << "/" << yellowGainedScore << "/" << yellowLostScore << "/" << yellowNumberOfStarts << std::endl;
    f.close();
}

void AccountingEngine::onNotify(Event &event)
{
    EventType eventType = event.getEventType();
    Color playerColor = event.getPlayer();

    switch (playerColor)
    {
    case RED:
        if (eventType == EVENT_NO_MOVE)
        {
            redWaitDuration += 1;
        }
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_ROW)
        {
            redGainedScore += 1;
        }
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_SQUARE)
        {
            redNumberOfStarts += 1;
        }
        else if (eventType == EVENT_PIECE_HIT)
        {
            redLostScore += 1;
        }
        break;
    case BLUE:
        if (eventType == EVENT_NO_MOVE)
        {
            blueWaitDuration += 1;
        }
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_ROW)
        {
            blueGainedScore += 1;
        }
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_SQUARE)
        {
            blueNumberOfStarts += 1;
        }
        else if (eventType == EVENT_PIECE_HIT)
        {
            blueLostScore += 1;
        }
        break;
    case GREEN:
        if (eventType == EVENT_NO_MOVE)
        {
            greenWaitDuration += 1;
        }
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_ROW)
        {
            greenGainedScore += 1;
        }
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_SQUARE)
        {
            greenNumberOfStarts += 1;
        }
        else if (eventType == EVENT_PIECE_HIT)
        {
            greenLostScore += 1;
        }
        break;
    case YELLOW:
        if (eventType == EVENT_NO_MOVE)
        {
            yellowWaitDuration += 1;
        }
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_ROW)
        {
            yellowGainedScore += 1;
        }
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_SQUARE)
        {
            yellowNumberOfStarts += 1;
        }
        else if (eventType == EVENT_PIECE_HIT)
        {
            yellowLostScore += 1;
        }
        break;
    default:
        break;
    }
}