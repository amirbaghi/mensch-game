#include "./Headers/Components/Actors/Piece.h"
#include "./Headers/Components/Events/Event.h"

Piece::Piece(Model *model) : Actor(model)
{
}

Piece::~Piece()
{
}

void Piece::setCurrentSquare(Square *square)
{
    this->currentSquare = square;
}

Square *Piece::getCurrentSquare()
{
    return this->currentSquare;
}

void Piece::setPieceColor(Color color)
{
    this->color = color;
}

Color Piece::getColor()
{
    return this->color;
}

void Piece::render()
{
    model->render();
}

void Piece::setHasPassedHomeSquare(bool hasPassedHomeSquare)
{
    this->hasPassedHomeSquare = hasPassedHomeSquare;
}

bool Piece::getHasPassedHomeSquare()
{
    return this->hasPassedHomeSquare;
}

void Piece::onNotify(Event &event)
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