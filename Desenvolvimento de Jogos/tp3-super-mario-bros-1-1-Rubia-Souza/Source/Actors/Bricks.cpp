//
// Created by rubia on 16/05/2025.
//

#include "Bricks.h"
#include "../Components/DrawComponents/DrawSpriteComponent.h"
#include "../Game.h"

Bricks::Bricks(Game *game, const std::string &texturePath, const Vector2& startPos) :
    Actor(game) {
    new DrawSpriteComponent(this, texturePath, Game::TILE_SIZE, Game::TILE_SIZE);

    new AABBColliderComponent(this, 0, 0, Game::TILE_SIZE, Game::TILE_SIZE, ColliderLayer::Blocks);

    this->startPos = startPos;
}

void Bricks::OnUpdate(float deltaTime) {
    if (GetPosition().y != startPos.y) {
        if (Math::NearZero(GetPosition().y - startPos.y, 1)) {
            SetPosition(startPos);
        } else {
            SetPosition(Vector2(startPos.x, Math::Lerp(GetPosition().y, startPos.y, deltaTime)));
        }
    }
}


void Bricks::OnHorizontalCollision(const float minOverlap, AABBColliderComponent* other) {

}

void Bricks::OnVerticalCollision(const float minOverlap, AABBColliderComponent *other) {
    if (minOverlap < 0) {
        SetPosition(startPos - Vector2(0, Game::TILE_SIZE));
    }
}

