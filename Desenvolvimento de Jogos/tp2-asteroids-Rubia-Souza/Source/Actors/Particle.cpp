//
// Created by rubia on 13/04/2025.
//

#include "Particle.h"

#include "Actor.h"
#include "../Random.h"
#include "../Game.h"
#include "../Components/DrawComponent.h"
#include "../Components/RigidBodyComponent.h"

Particle::Particle(class Game *game)
    :Actor(game)
    ,mLifeTime(1.0f)
{
    std::vector<Vector2> vertices = GenerateVertices(15, 5);
    Vector2 randStartingForce = GenerateRandomStartingForce(1200.0f, 1700.0f);

    mDrawComponent = new DrawComponent(this, vertices);
    mRigidBodyComponent = new RigidBodyComponent(this, 0.1);

    mRigidBodyComponent->ApplyForce(randStartingForce);
}

std::vector<Vector2> Particle::GenerateVertices(const int numVertices, const float radius)
{
    std::vector<Vector2> vertices;

    float angle = 0.0f;

    for (int i = 0; i < numVertices; i++) {
        float randLength = Random::GetFloatRange(0.5f, 1.0f) * radius;
        float x = randLength * Math::Cos(angle);
        float y = randLength * Math::Sin(angle);
        vertices.emplace_back(x, y);
        angle += Math::TwoPi / numVertices;
    }

    return vertices;
}

Vector2 Particle::GenerateRandomStartingForce(const float min, const float max)
{
    float randDirX = 0.0f;
    if (Random::GetFloat() < 0.5) {
        randDirX = 1.0;
    } else {
        randDirX = -1.0;
    }

    float randDirY = 0.0f;
    if (Random::GetFloat() < 0.5) {
        randDirY = 1.0;
    } else {
        randDirY = -1.0;
    }

    Vector2 minRandForce = Vector2(min, min);
    Vector2 maxRandForce = Vector2(max, max);
    Vector2 randForce = Random::GetVector(minRandForce, maxRandForce);

    return Vector2(randForce.x * randDirX, randForce.y * randDirY);
}

void Particle::OnUpdate(float deltaTime) {
    mLifeTime -= deltaTime;
    if (mLifeTime < 0.0f) {
        SetState(ActorState::Destroy);
    }
}
