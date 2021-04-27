#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "./Headers/Components/Accounting/AccountingEngine.h"
#include "./Headers/matplotlibcpp.h"

AccountingEngine::AccountingEngine()
{
}

AccountingEngine::~AccountingEngine()
{
}

AccountingEngine *AccountingEngine::instance()
{
    static AccountingEngine *instance = new AccountingEngine();
    return instance;
}

void AccountingEngine::initAccounting()
{
    // Delete the previous stats file (If exists)
    std::remove("stats.txt");

    // Initializing the counters for all players as 0
    redWaitDuration = 0;
    blueWaitDuration = 0;
    greenWaitDuration = 0;
    yellowWaitDuration = 0;

    redGainedScore = 0;
    blueGainedScore = 0;
    greenGainedScore = 0;
    yellowGainedScore = 0;

    redLostScore = 0;
    blueLostScore = 0;
    greenLostScore = 0;
    yellowLostScore = 0;

    redNumberOfStarts = 0;
    blueNumberOfStarts = 0;
    greenNumberOfStarts = 0;
    yellowNumberOfStarts = 0;

    redCoveredDistance = 0;
    blueCoveredDistance = 0;
    greenCoveredDistance = 0;
    yellowCoveredDistance = 0;
}

void AccountingEngine::writeOut(time_t time)
{

    std::ofstream f;
    f.open("stats.txt", std::ios::out | std::ios::app);
    f << (float)time / CLOCKS_PER_SEC << " " << redWaitDuration << "/" << redGainedScore << "/" << redLostScore << "/" << redNumberOfStarts << "/" << redCoveredDistance << " "
      << blueWaitDuration << "/" << blueGainedScore << "/" << blueLostScore << "/" << blueNumberOfStarts << "/" << blueCoveredDistance << " "
      << greenWaitDuration << "/" << greenGainedScore << "/" << greenLostScore << "/" << greenNumberOfStarts << "/" << greenCoveredDistance << " "
      << yellowWaitDuration << "/" << yellowGainedScore << "/" << yellowLostScore << "/" << yellowNumberOfStarts << "/" << yellowCoveredDistance << std::endl;
    f.close();
}

void AccountingEngine::plotOut()
{
    std::ifstream f("stats.txt");
    std::string tempstr;
    std::string line;
    double temp;

    std::vector<double> time_axis(1000);

    std::vector<double> redWaitDuration(1000);
    std::vector<double> redGainedScore(1000);
    std::vector<double> redLostScore(1000);
    std::vector<double> redNumberOfStarts(1000);
    std::vector<double> redCoveredDistance(1000);

    std::vector<double> blueWaitDuration(1000);
    std::vector<double> blueGainedScore(1000);
    std::vector<double> blueLostScore(1000);
    std::vector<double> blueNumberOfStarts(1000);
    std::vector<double> blueCoveredDistance(1000);

    std::vector<double> greenWaitDuration(1000);
    std::vector<double> greenGainedScore(1000);
    std::vector<double> greenLostScore(1000);
    std::vector<double> greenNumberOfStarts(1000);
    std::vector<double> greenCoveredDistance(1000);

    std::vector<double> yellowWaitDuration(1000);
    std::vector<double> yellowGainedScore(1000);
    std::vector<double> yellowLostScore(1000);
    std::vector<double> yellowNumberOfStarts(1000);
    std::vector<double> yellowCoveredDistance(1000);

    while (getline(f, line))
    {
        std::istringstream iss(line);

        iss >> temp;
        time_axis.push_back(temp);

        iss.ignore(1);
        iss >> temp;
        redWaitDuration.push_back(temp);
        iss.ignore(1);
        iss >> temp;
        redGainedScore.push_back(temp);
        iss.ignore(1);
        iss >> temp;
        redLostScore.push_back(temp);
        iss.ignore(1);
        iss >> temp;
        redNumberOfStarts.push_back(temp);
        iss.ignore(1);
        iss >> temp;
        redCoveredDistance.push_back(temp);

        iss.ignore(1);
        iss >> temp;
        blueWaitDuration.push_back(temp);
        iss.ignore(1);
        iss >> temp;
        blueGainedScore.push_back(temp);
        iss.ignore(1);
        iss >> temp;
        blueLostScore.push_back(temp);
        iss.ignore(1);
        iss >> temp;
        blueNumberOfStarts.push_back(temp);
        iss.ignore(1);
        iss >> temp;
        blueCoveredDistance.push_back(temp);

        iss.ignore(1);
        iss >> temp;
        greenWaitDuration.push_back(temp);
        iss.ignore(1);
        iss >> temp;
        greenGainedScore.push_back(temp);
        iss.ignore(1);
        iss >> temp;
        greenLostScore.push_back(temp);
        iss.ignore(1);
        iss >> temp;
        greenNumberOfStarts.push_back(temp);
        iss.ignore(1);
        iss >> temp;
        greenCoveredDistance.push_back(temp);

        iss.ignore(1);
        iss >> temp;
        yellowWaitDuration.push_back(temp);
        iss.ignore(1);
        iss >> temp;
        yellowGainedScore.push_back(temp);
        iss.ignore(1);
        iss >> temp;
        yellowLostScore.push_back(temp);
        iss.ignore(1);
        iss >> temp;
        yellowNumberOfStarts.push_back(temp);
        iss.ignore(1);
        iss >> temp;
        yellowCoveredDistance.push_back(temp);
    }

    matplotlibcpp::title("Wait Durations");

    matplotlibcpp::named_plot("Player Red", time_axis, redWaitDuration, "r");
    matplotlibcpp::named_plot("Player Blue", time_axis, blueWaitDuration, "b");
    matplotlibcpp::named_plot("Player Green", time_axis, greenWaitDuration, "g");
    matplotlibcpp::named_plot("Player Yellow", time_axis, yellowWaitDuration, "y");

    matplotlibcpp::legend();

    matplotlibcpp::save("wait_dur_chart.png");
    matplotlibcpp::clf();

    matplotlibcpp::title("Gained Scores");

    matplotlibcpp::named_plot("Player Red", time_axis, redGainedScore, "r");
    matplotlibcpp::named_plot("Player Blue", time_axis, blueGainedScore, "b");
    matplotlibcpp::named_plot("Player Green", time_axis, greenGainedScore, "g");
    matplotlibcpp::named_plot("Player Yellow", time_axis, yellowGainedScore, "y");

    matplotlibcpp::legend();

    matplotlibcpp::save("gained_scores_chart.png");
    matplotlibcpp::clf();

    matplotlibcpp::title("Lost Scores");

    matplotlibcpp::named_plot("Player Red", time_axis, redLostScore, "r");
    matplotlibcpp::named_plot("Player Blue", time_axis, blueLostScore, "b");
    matplotlibcpp::named_plot("Player Green", time_axis, greenLostScore, "g");
    matplotlibcpp::named_plot("Player Yellow", time_axis, yellowLostScore, "y");

    matplotlibcpp::legend();

    matplotlibcpp::save("lost_scores_chart.png");
    matplotlibcpp::clf();

    matplotlibcpp::title("Number of Starts");

    matplotlibcpp::named_plot("Player Red", time_axis, redNumberOfStarts, "r");
    matplotlibcpp::named_plot("Player Blue", time_axis, blueNumberOfStarts, "b");
    matplotlibcpp::named_plot("Player Green", time_axis, greenNumberOfStarts, "g");
    matplotlibcpp::named_plot("Player Yellow", time_axis, yellowNumberOfStarts, "y");

    matplotlibcpp::legend();

    matplotlibcpp::save("number_of_starts_chart.png");

    matplotlibcpp::clf();

    matplotlibcpp::title("Covered Distance");

    matplotlibcpp::named_plot("Player Red", time_axis, redCoveredDistance, "r");
    matplotlibcpp::named_plot("Player Blue", time_axis, blueCoveredDistance, "b");
    matplotlibcpp::named_plot("Player Green", time_axis, greenCoveredDistance, "g");
    matplotlibcpp::named_plot("Player Yellow", time_axis, yellowCoveredDistance, "y");

    matplotlibcpp::legend();

    matplotlibcpp::save("covered_distances_chart.png");
}

void AccountingEngine::onNotify(Event &event)
{
    EventType eventType = event.getEventType();
    Color playerColor = event.getPlayer();

    switch (playerColor)
    {
    case RED:
        if (eventType == EVENT_NO_MOVE)
        {
            redWaitDuration += 1;
        }
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_ROW)
        {
            redGainedScore += 1;
        }
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_SQUARE)
        {
            redNumberOfStarts += 1;
        }
        else if (eventType == EVENT_PIECE_HIT)
        {
            redLostScore += 1;
        }
        if (eventType != EVENT_NO_MOVE && eventType != EVENT_PIECE_HIT)
        {
            redCoveredDistance += 1;
        }
        break;
    case BLUE:
        if (eventType == EVENT_NO_MOVE)
        {
            blueWaitDuration += 1;
        }
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_ROW)
        {
            blueGainedScore += 1;
        }
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_SQUARE)
        {
            blueNumberOfStarts += 1;
        }
        else if (eventType == EVENT_PIECE_HIT)
        {
            blueLostScore += 1;
        }
        if (eventType != EVENT_NO_MOVE && eventType != EVENT_PIECE_HIT)
        {
            blueCoveredDistance += 1;
        }
        break;
    case GREEN:
        if (eventType == EVENT_NO_MOVE)
        {
            greenWaitDuration += 1;
        }
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_ROW)
        {
            greenGainedScore += 1;
        }
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_SQUARE)
        {
            greenNumberOfStarts += 1;
        }
        else if (eventType == EVENT_PIECE_HIT)
        {
            greenLostScore += 1;
        }
        if (eventType != EVENT_NO_MOVE && eventType != EVENT_PIECE_HIT)
        {
            greenCoveredDistance += 1;
        }
        break;
    case YELLOW:
        if (eventType == EVENT_NO_MOVE)
        {
            yellowWaitDuration += 1;
        }
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_ROW)
        {
            yellowGainedScore += 1;
        }
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_SQUARE)
        {
            yellowNumberOfStarts += 1;
        }
        else if (eventType == EVENT_PIECE_HIT)
        {
            yellowLostScore += 1;
        }
        if (eventType != EVENT_NO_MOVE && eventType != EVENT_PIECE_HIT)
        {
            yellowCoveredDistance += 1;
        }
        break;
    default:
        break;
    }
}