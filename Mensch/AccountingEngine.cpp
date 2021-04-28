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

void AccountingEngine::writeOut(double time)
{
    std::ofstream f;
    f.open("stats.txt", std::ios::out | std::ios::app);
    f << time << " " << redWaitDuration << "/" << redGainedScore << "/" << redLostScore << "/" << redNumberOfStarts << "/" << redCoveredDistance << " "
      << blueWaitDuration << "/" << blueGainedScore << "/" << blueLostScore << "/" << blueNumberOfStarts << "/" << blueCoveredDistance << " "
      << greenWaitDuration << "/" << greenGainedScore << "/" << greenLostScore << "/" << greenNumberOfStarts << "/" << greenCoveredDistance << " "
      << yellowWaitDuration << "/" << yellowGainedScore << "/" << yellowLostScore << "/" << yellowNumberOfStarts << "/" << yellowCoveredDistance << std::endl;
    f.close();
}

void AccountingEngine::plotOutCumulative()
{
    std::ifstream f("stats.txt");
    std::string tempstr;
    std::string line;
    double temp;

    std::vector<double> time_axis;

    std::vector<double> redWaitDuration;
    std::vector<double> redGainedScore;
    std::vector<double> redLostScore;
    std::vector<double> redNumberOfStarts;
    std::vector<double> redCoveredDistance;

    std::vector<double> blueWaitDuration;
    std::vector<double> blueGainedScore;
    std::vector<double> blueLostScore;
    std::vector<double> blueNumberOfStarts;
    std::vector<double> blueCoveredDistance;

    std::vector<double> greenWaitDuration;
    std::vector<double> greenGainedScore;
    std::vector<double> greenLostScore;
    std::vector<double> greenNumberOfStarts;
    std::vector<double> greenCoveredDistance;

    std::vector<double> yellowWaitDuration;
    std::vector<double> yellowGainedScore;
    std::vector<double> yellowLostScore;
    std::vector<double> yellowNumberOfStarts;
    std::vector<double> yellowCoveredDistance;

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

    f.close();

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

void AccountingEngine::plotOutWindowed(double interval)
{

    std::ifstream f("stats.txt");
    std::string tempstr;
    std::string line;
    double temp;
    double previous_time = 0.0;

    double previous_redWaitDuration = 0.0;
    double previous_blueWaitDuration = 0.0;
    double previous_greenWaitDuration = 0.0;
    double previous_yellowWaitDuration = 0.0;

    double previous_redGainedScore = 0.0;
    double previous_blueGainedScore = 0.0;
    double previous_greenGainedScore = 0.0;
    double previous_yellowGainedScore = 0.0;

    double previous_redLostScore = 0.0;
    double previous_blueLostScore = 0.0;
    double previous_greenLostScore = 0.0;
    double previous_yellowLostScore = 0.0;

    double previous_redNumberOfStarts = 0.0;
    double previous_blueNumberOfStarts = 0.0;
    double previous_greenNumberOfStarts = 0.0;
    double previous_yellowNumberOfStarts = 0.0;

    double previous_redCoveredDistance = 0.0;
    double previous_blueCoveredDistance = 0.0;
    double previous_greenCoveredDistance = 0.0;
    double previous_yellowCoveredDistance = 0.0;

    std::vector<double> time_axis;

    std::vector<double> redWaitDuration;
    std::vector<double> redGainedScore;
    std::vector<double> redLostScore;
    std::vector<double> redNumberOfStarts;
    std::vector<double> redCoveredDistance;

    std::vector<double> blueWaitDuration;
    std::vector<double> blueGainedScore;
    std::vector<double> blueLostScore;
    std::vector<double> blueNumberOfStarts;
    std::vector<double> blueCoveredDistance;

    std::vector<double> greenWaitDuration;
    std::vector<double> greenGainedScore;
    std::vector<double> greenLostScore;
    std::vector<double> greenNumberOfStarts;
    std::vector<double> greenCoveredDistance;

    std::vector<double> yellowWaitDuration;
    std::vector<double> yellowGainedScore;
    std::vector<double> yellowLostScore;
    std::vector<double> yellowNumberOfStarts;
    std::vector<double> yellowCoveredDistance;

    while (getline(f, line))
    {
        std::istringstream iss(line);

        iss >> temp;
        if (temp - previous_time >= interval)
        {
            previous_time = temp;
            time_axis.push_back(temp);

            iss.ignore(1);
            iss >> temp;
            redWaitDuration.push_back(temp - previous_redWaitDuration);
            previous_redWaitDuration = temp;
            iss.ignore(1);
            iss >> temp;
            redGainedScore.push_back(temp - previous_redGainedScore);
            previous_redGainedScore = temp;
            iss.ignore(1);
            iss >> temp;
            redLostScore.push_back(temp - previous_redLostScore);
            previous_redLostScore = temp;
            iss.ignore(1);
            iss >> temp;
            redNumberOfStarts.push_back(temp - previous_redNumberOfStarts);
            previous_redNumberOfStarts = temp;
            iss.ignore(1);
            iss >> temp;
            redCoveredDistance.push_back(temp - previous_redCoveredDistance);
            previous_redCoveredDistance = temp;

            iss.ignore(1);
            iss >> temp;
            blueWaitDuration.push_back(temp - previous_blueWaitDuration);
            previous_blueWaitDuration = temp;
            iss.ignore(1);
            iss >> temp;
            blueGainedScore.push_back(temp - previous_blueGainedScore);
            previous_blueGainedScore = temp;
            iss.ignore(1);
            iss >> temp;
            blueLostScore.push_back(temp - previous_blueLostScore);
            previous_blueLostScore = temp;
            iss.ignore(1);
            iss >> temp;
            blueNumberOfStarts.push_back(temp - previous_blueNumberOfStarts);
            previous_blueNumberOfStarts = temp;
            iss.ignore(1);
            iss >> temp;
            blueCoveredDistance.push_back(temp - previous_blueCoveredDistance);
            previous_blueCoveredDistance = temp;

            iss.ignore(1);
            iss >> temp;
            greenWaitDuration.push_back(temp - previous_greenWaitDuration);
            previous_greenWaitDuration = temp;
            iss.ignore(1);
            iss >> temp;
            greenGainedScore.push_back(temp - previous_greenGainedScore);
            previous_greenGainedScore = temp;
            iss.ignore(1);
            iss >> temp;
            greenLostScore.push_back(temp - previous_greenLostScore);
            previous_greenLostScore = temp;
            iss.ignore(1);
            iss >> temp;
            greenNumberOfStarts.push_back(temp - previous_greenNumberOfStarts);
            previous_greenNumberOfStarts = temp;
            iss.ignore(1);
            iss >> temp;
            greenCoveredDistance.push_back(temp - previous_greenCoveredDistance);
            previous_greenCoveredDistance = temp;

            iss.ignore(1);
            iss >> temp;
            yellowWaitDuration.push_back(temp - previous_yellowWaitDuration);
            previous_yellowWaitDuration = temp;
            iss.ignore(1);
            iss >> temp;
            yellowGainedScore.push_back(temp - previous_yellowGainedScore);
            previous_yellowGainedScore = temp;
            iss.ignore(1);
            iss >> temp;
            yellowLostScore.push_back(temp - previous_yellowLostScore);
            previous_yellowLostScore = temp;
            iss.ignore(1);
            iss >> temp;
            yellowNumberOfStarts.push_back(temp - previous_yellowNumberOfStarts);
            previous_yellowNumberOfStarts = temp;
            iss.ignore(1);
            iss >> temp;
            yellowCoveredDistance.push_back(temp - previous_yellowCoveredDistance);
            previous_yellowCoveredDistance = temp;
        }
    }

    f.close();

    matplotlibcpp::title("Wait Durations Windowed");

    matplotlibcpp::named_plot("Player Red", time_axis, redWaitDuration, "r");
    matplotlibcpp::named_plot("Player Blue", time_axis, blueWaitDuration, "b");
    matplotlibcpp::named_plot("Player Green", time_axis, greenWaitDuration, "g");
    matplotlibcpp::named_plot("Player Yellow", time_axis, yellowWaitDuration, "y");

    matplotlibcpp::legend();

    matplotlibcpp::save("wait_dur_windowed_chart.png");
    matplotlibcpp::clf();

    matplotlibcpp::title("Gained Scores Windowed");

    matplotlibcpp::named_plot("Player Red", time_axis, redGainedScore, "r");
    matplotlibcpp::named_plot("Player Blue", time_axis, blueGainedScore, "b");
    matplotlibcpp::named_plot("Player Green", time_axis, greenGainedScore, "g");
    matplotlibcpp::named_plot("Player Yellow", time_axis, yellowGainedScore, "y");

    matplotlibcpp::legend();

    matplotlibcpp::save("gained_scores_windowed_chart.png");
    matplotlibcpp::clf();

    matplotlibcpp::title("Lost Scores Windowed");

    matplotlibcpp::named_plot("Player Red", time_axis, redLostScore, "r");
    matplotlibcpp::named_plot("Player Blue", time_axis, blueLostScore, "b");
    matplotlibcpp::named_plot("Player Green", time_axis, greenLostScore, "g");
    matplotlibcpp::named_plot("Player Yellow", time_axis, yellowLostScore, "y");

    matplotlibcpp::legend();

    matplotlibcpp::save("lost_scores_windowed_chart.png");
    matplotlibcpp::clf();

    matplotlibcpp::title("Number of Starts Windowed");

    matplotlibcpp::named_plot("Player Red", time_axis, redNumberOfStarts, "r");
    matplotlibcpp::named_plot("Player Blue", time_axis, blueNumberOfStarts, "b");
    matplotlibcpp::named_plot("Player Green", time_axis, greenNumberOfStarts, "g");
    matplotlibcpp::named_plot("Player Yellow", time_axis, yellowNumberOfStarts, "y");

    matplotlibcpp::legend();

    matplotlibcpp::save("number_of_starts_windowed_chart.png");

    matplotlibcpp::clf();

    matplotlibcpp::title("Covered Distance Windowed");

    matplotlibcpp::named_plot("Player Red", time_axis, redCoveredDistance, "r");
    matplotlibcpp::named_plot("Player Blue", time_axis, blueCoveredDistance, "b");
    matplotlibcpp::named_plot("Player Green", time_axis, greenCoveredDistance, "g");
    matplotlibcpp::named_plot("Player Yellow", time_axis, yellowCoveredDistance, "y");

    matplotlibcpp::legend();

    matplotlibcpp::save("covered_distances_windowed_chart.png");
}

void AccountingEngine::plotOut()
{
    plotOutCumulative();
    matplotlibcpp::clf();
    plotOutWindowed(30.0);
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
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_SQUARE || eventType == EVENT_PIECE_MOVED_TO_HOME_SQUARE_FROM_HOME)
        {
            redNumberOfStarts += 1;
        }
        else if (eventType == EVENT_PIECE_HIT)
        {
            redLostScore += 1;
        }
        if (eventType != EVENT_NO_MOVE && eventType != EVENT_PIECE_HIT && eventType != EVENT_PIECE_MOVED_TO_HOME_SQUARE_FROM_HOME)
        {
            redCoveredDistance += event.getDiceNum();
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
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_SQUARE || eventType == EVENT_PIECE_MOVED_TO_HOME_SQUARE_FROM_HOME)
        {
            blueNumberOfStarts += 1;
        }
        else if (eventType == EVENT_PIECE_HIT)
        {
            blueLostScore += 1;
        }
        if (eventType != EVENT_NO_MOVE && eventType != EVENT_PIECE_HIT && eventType != EVENT_PIECE_MOVED_TO_HOME_SQUARE_FROM_HOME)
        {
            blueCoveredDistance += event.getDiceNum();
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
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_SQUARE || eventType == EVENT_PIECE_MOVED_TO_HOME_SQUARE_FROM_HOME)
        {
            greenNumberOfStarts += 1;
        }
        else if (eventType == EVENT_PIECE_HIT)
        {
            greenLostScore += 1;
        }
        if (eventType != EVENT_NO_MOVE && eventType != EVENT_PIECE_HIT && eventType != EVENT_PIECE_MOVED_TO_HOME_SQUARE_FROM_HOME)
        {
            greenCoveredDistance += event.getDiceNum();
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
        else if (eventType == EVENT_PIECE_MOVED_TO_HOME_SQUARE || eventType == EVENT_PIECE_MOVED_TO_HOME_SQUARE_FROM_HOME)
        {
            yellowNumberOfStarts += 1;
        }
        else if (eventType == EVENT_PIECE_HIT)
        {
            yellowLostScore += 1;
        }
        if (eventType != EVENT_NO_MOVE && eventType != EVENT_PIECE_HIT && eventType != EVENT_PIECE_MOVED_TO_HOME_SQUARE_FROM_HOME)
        {
            yellowCoveredDistance += event.getDiceNum();
        }
        break;
    default:
        break;
    }
}