//
// Created by Lucas N. Ferreira on 03 Aug 23.
//

#pragma once
#include "Actor.h"
#include "../Components/DrawComponent.h"

class Paddle : public Actor
{
public:
    Paddle(class Game* game);

    void OnProcessInput(const Uint8* keyState) override;
    void OnUpdate(float deltaTime) override;

    int GetWidth() const { return mWidth; }
    int GetHeight() const { return mHeight; }

private:
    int mDir;
    int mWidth;
    int mHeight;
    float mVerticalSpeed;

    DrawComponent* mDrawComponent;
};

