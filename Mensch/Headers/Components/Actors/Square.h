#ifndef SQUARE_H
#define SQUARE_H

#include <vector>
#include "./Actor.h"

class Piece;

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

    // IsHomeRowSquare Setter
    void setIsHomeRowSquare(bool isHomeRowSquare);

    // IsHomeRowSquare Getter
    bool getIsHomeRowSquare();

    // Square Color Setter
    void setColor(Color color);

    // Square Color Getter
    Color getColor();

    // Square Number Getter
    int getSquareNumber();

    // Square Number Setter
    void setSquareNumber(int squareNumber);

    // Render method
    void render() override;

    // On Notify Method
    void onNotify(Event &event) override;

private:
    // Pieces currently on this square (Max 2)
    std::vector<Piece *> pieces;

    // Is this Square a home square
    bool isHomeSquare;

    // Is this square a home row square
    bool isHomeRowSquare;

    // Square Color
    Color color;

    // Square number
    int squareNumber;
};

#endif