#include "./Headers/Game.h"

Game::Game()
{
}

Game::~Game()
{
    delete aiEngine;
    delete renderEngine;
    delete commandStream;
    delete uiEngine;
    delete physicsEngine;
    delete boardSpawner;
    delete pieceSpawner;
    delete board;

    for (auto it = pieces.begin(); it != pieces.end(); it++)
    {
        delete *it;
    }
}

Game *Game::instance()
{
    static Game *instance = new Game();
    return instance;
}

Board *Game::getBoard()
{
    return this->board;
}

std::vector<Piece *> Game::getPieces()
{
    return this->pieces;
}

Color Game::getCurrentTurn()
{
    return this->currentTurn;
}

void Game::setCurrentTurn(Color currentTurn)
{
    this->currentTurn = currentTurn;
}

void Game::nextTurn()
{
    // Go to next turn based on the curren turn
    switch (currentTurn)
    {
    case RED:
        currentTurn = BLUE;
        break;
    case BLUE:
        currentTurn = GREEN;
        break;
    case GREEN:
        currentTurn = YELLOW;
        break;
    case YELLOW:
        currentTurn = RED;
        break;

    default:
        break;
    }
}

void Game::initGame()
{
    // Setting the start time for the game
    startTime = clock();

    // Initializing the main modules of the game
    aiEngine = AIEngine::instance(this);
    renderEngine = RenderEngine::instance(this);
    commandStream = CommandStream::instance();
    uiEngine = UIEngine::instance(this);
    physicsEngine = PhysicsEngine::instance(this);

    // Creating and Loading models for squares and the board
    // And creating a spawner for the board, using the models
    BoardModel *boardModel = new BoardModel();
    SquareModel *squareModel = new SquareModel();
    boardModel->load();
    squareModel->load();
    boardSpawner = new BoardSpawner(boardModel, squareModel);

    // Creating and Loading the model for pieces
    // And creating a spawner for pieces, using the model
    PieceModel *pieceModel = new PieceModel();
    pieceModel->load();
    pieceSpawner = new PieceSpawner(pieceModel);

    // Spawning the Board
    board = boardSpawner->spawn();

    // Spawning the pieces
    for (int currentColor = RED; currentColor != NOCOLOR; currentColor++)
    {
        pieceSpawner->setSpawnColor(static_cast<Color>(currentColor));
        Piece *p1 = pieceSpawner->spawn();
        Piece *p2 = pieceSpawner->spawn();
        Piece *p3 = pieceSpawner->spawn();
        Piece *p4 = pieceSpawner->spawn();

        pieces.push_back(p1);
        pieces.push_back(p2);
        pieces.push_back(p3);
        pieces.push_back(p4);
    }

    // Initialize the current turn
    currentTurn = RED;
}

void Game::mainLoop()
{

    do
    {
        // Check if the game has ended
        for (int color = RED; color != NOCOLOR; color++)
        {
            std::vector<Square *> homeRow = getBoard()->getHomeRow(static_cast<Color>(color));
            bool isHomeRowFull = true;
            for (Square *s : homeRow)
            {
                if (s->getCurrentPieces().empty())
                {
                    isHomeRowFull = false;
                }
            }

            if (isHomeRowFull)
            {
                std::cout << 'RED WINS' << std::endl;
                return;
            }
        }

        // Get command from AI
        Command *command = aiEngine->generateMove(currentTurn);

        // Push it in the command stream
        commandStream->pushCommand(command);

        // Pop the most recent command
        Command *recentCommand = commandStream->popCommand();

        // Update the game
        physicsEngine->update(*recentCommand);

    } while (true);
}
