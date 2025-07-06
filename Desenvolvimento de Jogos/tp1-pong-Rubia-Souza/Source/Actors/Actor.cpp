// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Actor.h"
#include "../Game.h"
#include <algorithm>

// --------------
// TODO: PARTE 2
// --------------

Actor::Actor(Game* game)
        : mState(ActorState::Active)
        , mPosition(Vector2::Zero)
        , mScale(1.0f)
        , mRotation(0.0f)
        , mGame(game)
{
    // TODO 2.1 (1 linha): Utilize a função AddActor do jogo (mGame) para adicionar esse (this) objeto ao jogo
    mGame->AddActor(this);
}

Actor::~Actor()
{
    // TODO 2.2.1 (1 linha): Utilize a função RemoveActor do jogo (mGame) para remover esse (this) objeto do jogo
    mGame->RemoveActor(this);

    // TODO 2.2.2 (~5 linhas): Percorra o vetor de componentes (mComponents) deletando (delete) cada um deles e, em seguida,
    //  limpe (clear) o vetor de componentes.
    for (const Component* component : mComponents) {
        delete component;
    }
    mComponents.clear();
}

void Actor::Update(float deltaTime)
{
    // TODO 2.3 (~8 linhas): Verifique se o objeto está no estado (mState) ativo (ActorState::Active). Se estiver,
    //  percorra o vetor de componentes, chamando a função Update(deltaTime) para cada um deles e, em seguida,
    //  chame a função OnUpdate(deltaTime).
    if (mState == ActorState::Active) {
        for (Component* component : mComponents) {
            component->Update(deltaTime);
        }
        OnUpdate(deltaTime);
    }
}

void Actor::OnUpdate(float deltaTime)
{

}

void Actor::ProcessInput(const Uint8* keyState)
{
    // TODO 2.4 (~8 linhas): De forma similar ao método Update, verifique se o objeto está no estado (mState) ativo
    //  (ActorState::Active). Se estiver, percorra o vetor de componentes, chamando a função ProcessInput(keyState)
    //  para cada um deles e, em seguida, chame a função OnProcessInput(keyState).
    if (mState == ActorState::Active) {
        for (Component* component : mComponents) {
            component->ProcessInput(keyState);
        }
        OnProcessInput(keyState);
    }
}

void Actor::OnProcessInput(const Uint8* keyState)
{

}

void Actor::AddComponent(Component* c)
{
    mComponents.emplace_back(c);
    std::sort(mComponents.begin(), mComponents.end(), [](Component* a, Component* b) {
        return a->GetUpdateOrder() < b->GetUpdateOrder();
    });
}
