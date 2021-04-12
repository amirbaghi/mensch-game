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

    // Piece Setter
    void setPiece(Piece *piece);
    // Destination Setter
    void setDestination(Square *square);

private:
    // Destination Square of the move
    Square *destination;

    // The piece associated with the move
    Piece *piece;
};

#endif