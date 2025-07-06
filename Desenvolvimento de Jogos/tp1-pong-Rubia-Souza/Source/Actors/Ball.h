//
// Created by Lucas N. Ferreira on 03 Aug 23.
//

#pragma once
#include "Actor.h"
#include "../Components/DrawComponent.h"

class Ball : public Actor
{
public:
    Ball(struct Game *game);
    void OnUpdate(float deltaTime) override;

    void SetVelocity(const Vector2& velocity) { mVelocity = velocity; }

private:
    int mSize;
    Vector2 mVelocity;

    DrawComponent* mDrawComponent;
};
