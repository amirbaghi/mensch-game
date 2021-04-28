#include "./Headers/Components/Actors/Board.h"
#include "./Headers/Components/Events/Event.h"

Board::Board(Model *model) : Actor(model)
{
}

Board::~Board()
{
    for (auto s : regularSquares)
    {
        delete s;
    }
    regularSquares.clear();

    for (auto s : redHomeRow)
    {
        delete s;
    }
    redHomeRow.clear();

    for (auto s : yellowHomeRow)
    {
        delete s;
    }
    yellowHomeRow.clear();

    for (auto s : blueHomeRow)
    {
        delete s;
    }
    blueHomeRow.clear();

    for (auto s : greenHomeRow)
    {
        delete s;
    }
    greenHomeRow.clear();
}

void Board::render()
{
    model->render();
}

Color Board::getColor()
{
    return NOCOLOR;
}

void Board::onNotify(Event &event)
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