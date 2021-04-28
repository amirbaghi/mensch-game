#ifndef PIECEMODEL_H
#define PIECEMODEL_H

#include "./Model.h"

class PieceModel : public Model
{
public:
    PieceModel();
    ~PieceModel();

    // Load method
    void load();

    // Render method
    void render();
};

#endif