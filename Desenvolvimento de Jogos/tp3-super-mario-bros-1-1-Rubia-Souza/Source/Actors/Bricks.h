//
// Created by rubia on 16/05/2025.
//

#ifndef BRICKS_H
#define BRICKS_H
#include "Block.h"


class Bricks : public Actor {
private:
    Vector2 startPos;

public:
    Bricks(Game* game, const std::string &texturePath, const Vector2& startPos);

    void OnUpdate(float deltaTime) override;

    void OnHorizontalCollision(const float minOverlap, AABBColliderComponent* other) override;
    void OnVerticalCollision(const float minOverlap, AABBColliderComponent* other) override;
};



#endif //BRICKS_H
