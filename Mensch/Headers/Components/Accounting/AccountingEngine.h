#ifndef ACCOUNTINGENGINE_H
#define ACCOUNTINGENGINE_H

#include <chrono>
#include "../Observer.h"
#include "../Events/Event.h"

class AccountingEngine : public Observer
{
public:
    ~AccountingEngine();

    // On Notify Method
    void onNotify(Event &event);

    // Instance Method
    static AccountingEngine *instance();

    // Method to write out the current stats to file
    void writeOut(double time);

    // Method to plot out the cumulative chart
    void plotOutCumulative();

    // Method to plot out the windowed chart (give interval in seconds)
    void plotOutWindowed(double interval);

    // Method to plot out the stats file to a .png 
    void plotOut();

    // Init method
    void initAccounting();

private:
    // Private Constructors
    AccountingEngine();

    // Waiting Duration:
    // The number of times that the player has tossed a dice and wasn't able to make a move
    int redWaitDuration;
    int blueWaitDuration;
    int greenWaitDuration;
    int yellowWaitDuration;

    // Score Gained:
    // The number of times the player has moved a piece into a home row square
    int redGainedScore;
    int blueGainedScore;
    int greenGainedScore;
    int yellowGainedScore;

    // Score Lost:
    // The number of times the player has lost a score
    int redLostScore;
    int blueLostScore;
    int greenLostScore;
    int yellowLostScore;

    // Number of Starts:
    // The number of time the player has brought a piece into the field
    int redNumberOfStarts;
    int blueNumberOfStarts;
    int greenNumberOfStarts;
    int yellowNumberOfStarts;

    // Covered Distance:
    // The distance covered by the player
    int redCoveredDistance;
    int blueCoveredDistance;
    int greenCoveredDistance;
    int yellowCoveredDistance;
};

#endif