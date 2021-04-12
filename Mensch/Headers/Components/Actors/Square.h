#ifndef SQUARE_H
#define SQUARE_H

#include <vector>
#include "./Actor.h"
#include "../Model/Model.h"
#include "./Square.h"
#include "./Piece.h"

class Square : public Actor
{
public:
    Square(Model *model);
    ~Square();

    // Add Piece to the current pieces of this square
    void addPiece(Piece *piece);

    // Remove Piece from this square
    void removePiece(Piece *piece);

    // Current Pieces Getter
    std::vector<Piece *> getCurrentPieces();

    // IsHomeSquare Setter
    void setIsHomeSquare(bool isHomeSquare);

    // IsHomeSquare Getter
    bool getIsHomeSquare();

    // Square Color Setter
    void setColor(Color color);

    // Square Color Getter
    Color getColor();

    // Render method
    void render();

    // On Notify Method
    void onNotify(Event event, const Actor &actor);

private:
    // Pieces currently on this square (Max 2)
    std::vector<Piece *> pieces;

    // Is this Square a home square
    bool isHomeSquare;

    // Square Color
    Color color;
};

#endif