//
// Created by Lucas N. Ferreira on 03 Aug 23.
//

#include "Paddle.h"
#include "../Game.h"

// --------------
// TODO: PARTE 3
// --------------

Paddle::Paddle(Game* game)
        :Actor(game)
        ,mDir(0)
        ,mWidth(10)
        ,mHeight(70)
        ,mVerticalSpeed(500.0f)
        ,mDrawComponent(nullptr)
{
    // TODO 1 (1 linha): Crie um novo componente visual (DrawComponent) e atribua ao ponteiro mDrawComponent
    mDrawComponent = new DrawComponent(this, mWidth, mHeight);
}

void Paddle::OnProcessInput(const uint8_t* state)
{
    // TODO 2.1 (1 linha): Reinicialize a direção da raquete (mDir) para 0
    mDir = 0;

    // TODO 2.2 (~4 linhas): Verifique se tecla w está sendo pressionada. Se estiver, altere a direção (mDir) para -1
    if (state[SDL_SCANCODE_W]) {
        mDir = -1;
    }

    // TODO 2.3 (~4 linhas): Verifique se tecla s está sendo pressionada. Se estiver, altere a direção (mDir) para +1
    if (state[SDL_SCANCODE_S]) {
        mDir = 1;
    }
}

void Paddle::OnUpdate(float deltaTime)
{
    if (mDir != 0)
    {
        // TODO 3.3.1 (1 linha): Some à coordenada y da posição da raquete (mPosition.y) a velocidade da raquete
        //  (mVerticalSpeed) multiplicada pela sua direção (mDir) e pelo tempo decorrido desde o último quadro (deltaTime)
        mPosition.y += mVerticalSpeed * mDir * deltaTime;

        // TODO 3.3.2 (~8 linhas): Limite a coordenada y da raquete para que ela não ultrapasse os limites superior e
        //  inferior da tela
        if (mPosition.y < mHeight / 2) {
            mPosition.y = mHeight / 2;
        } else if (mPosition.y > mGame->GetWindowHeight() - mHeight / 2) {
            mPosition.y = mGame->GetWindowHeight() - mHeight / 2;
        }
    }
}
