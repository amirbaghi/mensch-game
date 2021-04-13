#include "./Headers/Components/Actors/Square.h"
#include "./Headers/Components/Events/Event.h"
#include "./Headers/Components/Actors/Piece.h"

#include <algorithm>

Square::Square(Model *model) : Actor(model)
{
}

Square::~Square()
{
}

void Square::addPiece(Piece *piece)
{
    pieces.push_back(piece);
}

void Square::removePiece(Piece *piece)
{
    pieces.erase(std::remove(pieces.begin(), pieces.end(), piece), pieces.end());
}

std::vector<Piece *> Square::getCurrentPieces()
{
    return this->pieces;
}

void Square::setIsHomeSquare(bool isHomeSquare)
{
    this->isHomeSquare = isHomeSquare;
}

bool Square::getIsHomeSquare()
{
    return this->isHomeSquare;
}

void Square::setIsHomeRowSquare(bool isHomeRowSquare)
{
    this->isHomeRowSquare = isHomeRowSquare;
}

bool Square::getIsHomeRowSquare()
{
    return this->isHomeRowSquare;
}

void Square::setColor(Color color)
{
    this->color = color;
}

Color Square::getColor()
{
    return this->color;
}

int Square::getSquareNumber()
{
    return this->squareNumber;
}

void Square::setSquareNumber(int squareNumber)
{
    this->squareNumber = squareNumber;
}

void Square::render()
{
    model->render();
}

void Square::onNotify(Event &event)
{
    // If the event has not happened for this actor
    if (event.getActor() != this)
    {
        // React accordingly to the event
        switch (event.getEventType())
        {
        case EVENT_PIECE_MOVED:
            break;
        case EVENT_PIECE_MOVED_SIX:
            break;
        case EVENT_NO_MOVE:
            break;
        default:
            break;
        }
    }
}