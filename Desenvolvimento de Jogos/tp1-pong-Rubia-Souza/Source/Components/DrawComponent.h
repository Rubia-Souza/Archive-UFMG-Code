//
// Created by Lucas N. Ferreira on 03 Aug 23.
//

#pragma once
#include "Component.h"
#include <SDL.h>

class DrawComponent : public Component
{
public:
    // (Lower draw order corresponds with further back)
    DrawComponent(class Actor* owner, int width = 0, int height = 0, int drawOrder = 100);
    ~DrawComponent();

    virtual void Draw(SDL_Renderer* renderer);

    int GetDrawOrder() const { return mDrawOrder; }
    int GetWidth() const { return mWidth; }
    int GetHeight() const { return mHeight; }
protected:
    int mDrawOrder;
    int mWidth;
    int mHeight;
};
