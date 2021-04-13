#ifndef PIECE_H
#define PIECE_H

#include "./Actor.h"
#include "../Model/PieceModel.h"
#include "./Square.h"
#include "../Color.h"

class Piece : public Actor
{
public:
    Piece(PieceModel *model);
    ~Piece();

    // Set Current Square
    void setCurrentSquare(Square *square);

    // Get Current Square
    void getCurrentSquare();

    // Set Piece Color
    void setPieceColor(Color color);

    // Get Piece Color
    Color getPieceColor();

    // Render method
    void render();

    // On Notify Method
    void onNotify(Event event, const Actor &actor);

private:
    // Current Square
    Square *currentSquare;

    // Piece Color
    Color color;
};

#endif