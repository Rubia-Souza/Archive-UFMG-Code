//
// Created by rubia on 13/04/2025.
//

#ifndef PARTICLE_H
#define PARTICLE_H

#include "Actor.h"

class Particle : public Actor {
public:
    Particle(class Game* game);

    void OnUpdate(float deltaTime) override;

private:
    std::vector<Vector2> GenerateVertices(int numVertices, float radius);
    Vector2 GenerateRandomStartingForce(float min, float max);

    float mLifeTime;

    class DrawComponent* mDrawComponent;
    class RigidBodyComponent* mRigidBodyComponent;
};



#endif //PARTICLE_H
