#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include "./Model.h"

class BoardModel : public Model
{
public:
    BoardModel();
    ~BoardModel();

    // Load method
    void load();

    // Render method
    void render();
};

#endif