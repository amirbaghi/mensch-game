#include "./Headers/Components/AI/AIEngine.h"
#include "./Headers/Components/Command/MoveCommand.h"
#include "./Headers/Components/Command/IdleCommand.h"

AIEngine::AIEngine()
{
}

AIEngine::AIEngine(Game *game)
{
    this->game = game;
}

AIEngine *AIEngine::instance(Game *game)
{
    static AIEngine *instance = new AIEngine(game);
    return instance;
}

Command *AIEngine::generateMove(Color player)
{
    std::vector<Square *> regularSquares = this->game->getBoard()->getRegularSquares();
    std::vector<Square *> homeRowSquares = this->game->getBoard()->getHomeRow(player);

    // Simulate dice throw
    int diceNum = 1 + (std::rand() % (6 - 1 + 1));

    // Collect pieces of this color
    std::vector<Piece *> pieces;

    for (Piece *p : game->getPieces())
    {
        if (p->getPieceColor() == player)
        {
            pieces.push_back(p);
        }
    }

    // Selecting a piece randomly and trying to move it
    for (int i = 0; i < 4; i++)
    {
        int randomElement = std::rand() % pieces.size();

        auto p = pieces[randomElement];

        // If the piece is out of the board
        if (p->getCurrentSquare() == nullptr)
        {
            // If we have a six
            if (diceNum == 6)
            {
                Square *destination;

                // Finding the destination
                for (Square *s : regularSquares)
                {
                    if (s->getIsHomeSquare() && s->getColor() == player)
                    {
                        destination = s;
                    }
                }

                MoveCommand *command = new MoveCommand();

                command->setPiece(p);
                command->setDiceNum(diceNum);
                command->setDestination(destination);

                return command;
            }
        }

        // If the piece is on the board (but not on the home row)
        else if (!(p->getCurrentSquare()->getIsHomeRowSquare()))
        {

            // See if you can place it on the home row
            // Finding the home square for this player
            Square *homeSquare;
            for (Square *s : regularSquares)
            {
                if (s->getIsHomeSquare() && s->getColor() == player)
                {
                    homeSquare = s;
                }
            }

            // Calculate the distance to the home square from the current square
            int difference;
            if (homeSquare->getSquareNumber() < p->getCurrentSquare()->getSquareNumber())
            {
                difference = (homeSquare->getSquareNumber() * regularSquares.size()) - p->getCurrentSquare()->getSquareNumber();
            }
            else
            {
                difference = homeSquare->getSquareNumber() - p->getCurrentSquare()->getSquareNumber();
            }

            // See if it's possible to place the piece in a home row square
            if (diceNum > difference && diceNum < difference + 5)
            {
                int homeRowSquareNumber = diceNum - difference;

                Square *homeRowSquare = homeRowSquares[homeRowSquareNumber - 1];

                // Check to see if there is already a piece in the selected home row square
                if (homeRowSquare->getCurrentPieces().empty())
                {
                    MoveCommand *command = new MoveCommand();

                    command->setPiece(p);
                    command->setDiceNum(diceNum);
                    command->setDestination(homeRowSquare);

                    return command;
                }
            }
            // else See if you can place it further up
            else
            {
                // Get the destiantion square
                Square *destination = regularSquares[((p->getCurrentSquare()->getSquareNumber() + diceNum) % regularSquares.size()) - 1];

                // If there is one or zero pieces on the square
                if (destination->getCurrentPieces().size() < 2)
                {
                    // Seeing if there is a different color piece in the square
                    bool squareIsOccupied = false;
                    for (Piece *piece : destination->getCurrentPieces())
                    {
                        if (piece->getPieceColor() != player)
                        {
                            squareIsOccupied = true;
                        }
                    }

                    // If the square is not occupied by another color piece, we are good to go
                    if (!squareIsOccupied)
                    {
                        MoveCommand *command = new MoveCommand();

                        command->setPiece(p);
                        command->setDiceNum(diceNum);
                        command->setDestination(destination);

                        return command;
                    }
                }
            }
        }
    }

    // If we couldn't move none of the pieces, return an idle move
    IdleCommand *command = new IdleCommand();

    return command;
}