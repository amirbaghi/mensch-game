#include "./Headers/Components/Spawner/BoardSpawner.h"
#include "./Headers/Components/Actors/Square.h"

BoardSpawner::BoardSpawner(BoardModel *model, SquareModel *squareModel) : Spawner(model)
{
    this->squareModel = squareModel;
}

BoardSpawner::~BoardSpawner()
{
    delete squareModel;
}

Board *BoardSpawner::spawn()
{
    // Spawning a new board
    Board *board = new Board(this->model);

    // Generating the squares of the board
    std::vector<Square *> regSquares;
    regSquares.reserve(40);

    int currentSquareNumber = 1;
    for (int currentColor = RED; currentColor != NOCOLOR; currentColor++)
    {
        // Generating the home square for the current color
        Square *homeSquare = new Square(squareModel);
        homeSquare->setIsHomeSquare(true);
        homeSquare->setColor(static_cast<Color>(currentColor));
        homeSquare->setIsHomeRowSquare(false);
        homeSquare->setSquareNumber(currentSquareNumber);
        currentSquareNumber++;

        regSquares.push_back(homeSquare);

        // Generating the regular squares between the home square of this color and the next color
        for (int j = 0; j < 9; j++)
        {
            Square *regSquare = new Square(squareModel);
            regSquare->setIsHomeSquare(false);
            regSquare->setColor(NOCOLOR);
            regSquare->setIsHomeRowSquare(false);
            homeSquare->setSquareNumber(currentSquareNumber);
            currentSquareNumber++;

            regSquares.push_back(regSquare);
        }

        // Generating the home row squares for the current color
        std::vector<Square *> homeRowSquares;
        for (int j = 0; j < 4; j++)
        {
            Square *homeRowSquare = new Square(squareModel);
            homeRowSquare->setIsHomeSquare(false);
            homeRowSquare->setColor(static_cast<Color>(currentColor));
            homeRowSquare->setIsHomeRowSquare(true);
            homeRowSquare->setSquareNumber(j + 1);

            homeRowSquares.push_back(homeRowSquare);
        }

        board->setHomeRow(homeRowSquares, static_cast<Color>(currentColor));
    }

    board->setRegularSquares(regSquares);

    return board;
}