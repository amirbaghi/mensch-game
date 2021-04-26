#ifndef ACCOUNTINGENGINE_H
#define ACCOUNTINGENGINE_H

#include "../Observer.h"

class AccountingEngine : public Observer
{
public:
    ~AccountingEngine();

    // On Notify Method
    void onNotify(Event& event);

private:
    // Private Constructors
    AccountingEngine();

    // Waiting Duration:
    // The number of times that the player has tossed a dice and wasn't able to make a move
    

};

#endif