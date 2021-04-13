#include "./Headers/Components/Actors/Board.h"

Board::Board(Model *model) : Actor(model)
{
}

Board::~Board()
{
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