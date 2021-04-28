#ifndef SQUAREMODEL_H
#define SQUAREMODEL_H

#include "./Model.h"

class SquareModel : public Model
{
public:
    SquareModel();
    ~SquareModel();

    // Load method
    void load();

    // Render method
    void render();
};

#endif