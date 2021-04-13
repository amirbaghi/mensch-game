#ifndef PIECE_H
#define PIECE_H

#include "./Actor.h"
#include "./Square.h"
#include "../Color.h"

class Piece : public Actor
{
public:
    Piece(Model *model);
    ~Piece();

    // Set Current Square
    void setCurrentSquare(Square *square);

    // Get Current Square
    Square* getCurrentSquare();

    // Set Piece Color
    void setPieceColor(Color color);

    // Get Piece Color
    Color getPieceColor();

    // Render method
    void render() override;

    // On Notify Method
    void onNotify(Event& event) override;

private:
    // Current Square
    Square *currentSquare;

    // Piece Color
    Color color;
    
    // Is piece in place
    bool isInPlace;
};

#endif