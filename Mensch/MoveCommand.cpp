#include "./Headers/Components/Command/MoveCommand.h"
#include <unistd.h>
#include <iostream>

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

Event *MoveCommand::execute(bool shouldLog)
{

    Square *source = this->piece->getCurrentSquare();

    // First remove the piece from the previous square (If it's already in the game)
    if (this->piece->getCurrentSquare() != nullptr)
    {
        this->piece->getCurrentSquare()->removePiece(this->piece);

        // Check if the piece has already passed its home square at least once
        if (this->piece->getCurrentSquare()->getIsHomeSquare() && this->piece->getCurrentSquare()->getColor() == this->piece->getColor())
        {
            this->piece->setHasPassedHomeSquare(true);
        }
    }

    // Add the piece to the new square
    this->destination->addPiece(this->piece);

    // Set the current square for the piece accordingly
    this->piece->setCurrentSquare(this->destination);

    if (shouldLog)
    {
        // Logging the move
        switch (this->piece->getColor())
        {
        case RED:
            std::cout << "RED ";
            break;
        case BLUE:
            std::cout << "BLUE ";
            break;
        case GREEN:
            std::cout << "GREEN ";
            break;
        case YELLOW:
            std::cout << "YELLOW ";
            break;
        default:
            break;
        }

        std::cout << "MOVED A PIECE FROM ";
        if (source == nullptr)
        {
            std::cout << "HOME";
        }
        else
        {
            std::cout << "SQUARE " << source->getSquareNumber();
        }
        std::cout << " TO ";
        if (destination->getIsHomeRowSquare())
        {
            std::cout << "HOME ROW ";
        }
        std::cout << "SQUARE " << destination->getSquareNumber() << std::endl;
    }

    // Generating the appropriate event
    Event *e = new Event();

    e->setActor(this->piece);
    e->setPlayer(this->player);
    e->setDiceNum(this->diceNum);

    if (this->destination->getIsHomeRowSquare())
    {
        e->setEventType(EVENT_PIECE_MOVED_TO_HOME_ROW);
    }
    else if (this->destination->getIsHomeSquare() && this->destination->getColor() == this->piece->getColor())
    {
        if (source == nullptr)
        {
            e->setEventType(EVENT_PIECE_MOVED_TO_HOME_SQUARE_FROM_HOME);
        }
        else
        {
            e->setEventType(EVENT_PIECE_MOVED_TO_HOME_SQUARE);
        }
    }
    else
    {
        e->setEventType(EVENT_PIECE_MOVED);
    }

    return e;
}
