//
// Created by rubia on 02/04/2025.
//

#ifndef WALL_H
#define WALL_H
#include "Actor.h"
#include "../Components/DrawComponent.h"

class Wall : public Actor {
public:
    Wall(class Game* game);

    int GetWidth() const { return mWidth; }
    int GetHeight() const { return mHeight; }

private:
    int mWidth;
    int mHeight;
    DrawComponent* mDrawComponent;
};

#endif //WALL_H
