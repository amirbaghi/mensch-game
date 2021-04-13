#include "./Headers/Components/Command/MoveCommand.h"

MoveCommand::MoveCommand()
{
}

MoveCommand::~MoveCommand()
{
}

Piece *MoveCommand::getPiece()
{
    return this->piece;
}

Square *MoveCommand::getSquare()
{
    return this->destination;
}

void MoveCommand::setPiece(Piece *piece)
{
    this->piece = piece;
}

void MoveCommand::setDestination(Square *square)
{
    this->destination = square;
}

int MoveCommand::getDiceNum()
{
    return this->diceNum;
}

void MoveCommand::setDiceNum(int diceNum)
{
    this->diceNum = diceNum;
}

Event *MoveCommand::execute()
{

    // First remove the piece from the previous square
    this->piece->getCurrentSquare()->removePiece(this->piece);

    // Add the piece to the new square
    this->destination->addPiece(this->piece);

    // Set the current square for the piece accordingly
    this->piece->setCurrentSquare(this->destination);


    Event *e = new Event();

    e->setActor(this->piece);

    if (diceNum == 6)
    {
        e->setEventType(EVENT_PIECE_MOVED_SIX);
    }
    else
    {
        e->setEventType(EVENT_PIECE_MOVED);
    }

    return e;
}
