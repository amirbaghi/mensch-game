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

    for (auto p : pieces)
    {
        delete p;
    }
    pieces.clear();
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

ExecMode Game::getExecutionMode()
{
    return this->executionMode;
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

void Game::resetState()
{
    // Setting the start time for the game
    startTime = clock();

    // Clear the previous Game state
    delete board;

    for (auto p : pieces)
    {
        delete p;
    }
    pieces.clear();

    // Initialize the game state with new values (reset)

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

void Game::initGame()
{
    // Setting the start time for the game
    startTime = clock();

    std::srand((unsigned int)std::time(NULL));

    // Initializing the main modules of the game
    aiEngine = AIEngine::instance(this);
    renderEngine = RenderEngine::instance(this);
    commandStream = CommandStream::instance();
    uiEngine = UIEngine::instance(this);
    physicsEngine = PhysicsEngine::instance(this);
    accountingEngine = AccountingEngine::instance();

    // Subscribing the accounting engine to the physics engine
    physicsEngine->addObserver(accountingEngine);

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

    long int count = 0;
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
                    break;
                }
            }

            // If a home row is full
            if (isHomeRowFull)
            {
                // Print only if we are executing on single run mode
                if (executionMode == SINGLE_RUN)
                {
                // Print the winner
                switch (color)
                {
                case RED:
                    std::cout << "RED";
                    break;
                case BLUE:
                    std::cout << "BLUE";
                    break;
                case GREEN:
                    std::cout << "GREEN";
                    break;
                case YELLOW:
                    std::cout << "YELLOW";
                    break;
                default:
                    break;
                }
                std::cout << " WINS" << std::endl;

                // Print the number of turns
                std::cout << "Number of Turns: ";
                std::cout << count << std::endl;

                // Print the elapsed time
                std::cout << "Elapsed Time: " << float(clock() - startTime) / CLOCKS_PER_SEC << std::endl;
                }

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

        // Delete the recent command
        delete recentCommand;

        count++;

    } while (true);
}

void Game::run()
{
    // Choose the execution mode (Decided by user input)
    int type = 1;
    while (true)
    {
        std::cout << "\033[H\033[J";
        std::cout << "Mensch.\nChoose the desired execution mode: (Enter 1 for Single Run, 2 for Profiling)\n";
        std::cin >> type;

        if (type == 1)
        {
            this->executionMode = SINGLE_RUN;
            std::cout << "\033[H\033[J";
            break;
        }
        else if (type == 2)
        {
            this->executionMode = PROFILING;
            std::cout << "\033[H\033[J";
            break;
        }
    }

    // Initialize the game for the first time
    this->initGame();

    // Running the game
    this->mainLoop();

    // Profiling Execution (Game is run 1000 times)
    if (this->executionMode == PROFILING)
    {
        for (int i = 0; i < 999; i++)
        {
            // Reset the game state
            this->resetState();

            // Run another round of the game
            this->mainLoop();

            // Write out the record for this round
            this->accountingEngine->writeOut(clock());
        }
    }
}
