#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "./Actor.h"
#include "./Square.h"
#include "../Color.h"

class Board : public Actor
{
public:
    Board(Model *model);
    ~Board();

    // Regular Squares Getter
    std::vector<Square *> getRegularSquares();

    // Home Row Getter (Based on player color)
    std::vector<Square *> getHomeRow(Color color);

    // Regular Squares Setter
    void setRegularSquares(std::vector<Square *> squares);

    // Home Row Setter (Based on player color)
    void setHomeRow(std::vector<Square *> squares, Color color);

    // Render method
    void render() override;

    // On Notify Method
    void onNotify(Event& event) override;

private:
    // Regular Squares of the Board
    std::vector<Square *> regularSquares;

    // Home Rows for Each Player
    std::vector<Square *> redHomeRow;
    std::vector<Square *> greenHomeRow;
    std::vector<Square *> blueHomeRow;
    std::vector<Square *> yellowHomeRow;
};

#endif