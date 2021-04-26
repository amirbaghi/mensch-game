#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "./Command.h"
#include "../Actors/Piece.h"
#include "../Actors/Square.h"

class MoveCommand : public Command
{
public:
    MoveCommand();
    ~MoveCommand();

    // Piece Getter
    Piece *getPiece();
    // Destination Getter
    Square *getSquare();
    // Dice Number Getter
    int getDiceNum();

    // Piece Setter
    void setPiece(Piece *piece);
    // Destination Setter
    void setDestination(Square *square);
    // Dice Number Setter
    void setDiceNum(int diceNum);

    // Execute command
    Event *execute(bool shouldLog);

private:
    // Destination Square of the move
    Square *destination;

    // The piece associated with the move
    Piece *piece;

    // Dice Number
    int diceNum;
};

#endif