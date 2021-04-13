#include "./Headers/Components/Actors/Board.h"
#include "./Headers/Components/Events/Event.h"

Board::Board(Model *model) : Actor(model)
{
}

Board::~Board()
{
}

void Board::render()
{
    model->render();
}

void Board::onNotify(Event &event)
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

std::vector<Square *> Board::getRegularSquares()
{
    return this->regularSquares;
}

std::vector<Square *> Board::getHomeRow(Color color)
{
    switch (color)
    {
    case RED:
        return this->redHomeRow;
        break;
    case BLUE:
        return this->blueHomeRow;
        break;
    case GREEN:
        return this->greenHomeRow;
        break;
    case YELLOW:
        return this->yellowHomeRow;
        break;
    default:
        break;
    }
}

void Board::setRegularSquares(std::vector<Square *> squares)
{
    this->regularSquares = squares;
}

void Board::setHomeRow(std::vector<Square *> squares, Color color)
{
    switch (color)
    {
    case RED:
        this->redHomeRow = squares;
        break;
    case BLUE:
        this->blueHomeRow = squares;
        break;
    case GREEN:
        this->greenHomeRow = squares;
        break;
    case YELLOW:
        this->yellowHomeRow = squares;
        break;

    default:
        break;
    }
}