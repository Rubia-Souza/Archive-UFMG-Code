//
// Created by rubia on 02/04/2025.
//

#include "Wall.h"

#include "../Game.h"

Wall::Wall(class Game *game) : Actor(game),
                               mWidth(10),
                               mHeight(GetGame()->GetWindowHeight()),
                               mDrawComponent(nullptr)
{
    mDrawComponent = new DrawComponent(this, mWidth, mHeight);
}

