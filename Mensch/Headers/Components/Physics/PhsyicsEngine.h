#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include "../Actors/Piece.h"
#include "../Subject.h"

class PhysicsEngine : public Subject
{
public:
    ~PhysicsEngine();

    // Instance Method
    static PhysicsEngine& instance();

    // Update Piece Method
    void updatePiece(Piece& piece);

private:
    // Private Constructor
    PhysicsEngine();
};

#endif