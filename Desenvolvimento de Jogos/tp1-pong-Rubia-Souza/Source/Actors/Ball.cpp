//
// Created by Lucas N. Ferreira on 03 Aug 23.
//

#include "Ball.h"
#include "../Game.h"

// --------------
// TODO: PARTE 3
// --------------

const float MAX_VELOCITY_X = 900.0f;
const float VELOCITY_INCREASE_RATE = 1.05f;

Ball::Ball(struct Game *game)
      :Actor(game)
      ,mSize(15)
      ,mVelocity(Vector2::Zero)
      ,mDrawComponent(nullptr)
{
    // TODO 3.1 (1 linha): Crie um novo componente visual (DrawComponent) e atribua ao ponteiro mDrawComponent
    mDrawComponent = new DrawComponent(this, mSize, mSize);
}

void Ball::OnUpdate(float deltaTime)
{
    Vector2 pos = GetPosition();

    // TODO 3.2.1 (1 linha): Some à posição horizontal da bola (pos.x) a sua velocidade horizontal
    //  (mVelocity.x) multiplicado pelo tempo decorrido desde o último quadro (deltaTime)
    pos.x += mVelocity.x * deltaTime;

    // TODO 3.2.2 (1 linha): Some à posição vertical da bola (pos.y) a sua velocidade vertical
    //  (mVelocity.y) multiplicado pelo tempo decorrido desde o último quadro (deltaTime)
    pos.y += mVelocity.y * deltaTime;

    // Get player's paddle
    Paddle *paddle = GetGame()->GetPaddle1();
    Wall *wall = GetGame()->GetWall();

    // TODO 3.2.3 (~2 linhas): Calcule as distâncias vertical e horizontal entra a bola e a raquete.
    //  Utilize a função paddle->GetPosition() para acessar a posição da raquete.
    float horizontalDistance = Math::Abs(paddle->GetPosition().x - pos.x);
    float verticalDistance = Math::Abs(paddle->GetPosition().y - pos.y);

    // TODO 3.2.4 (~7 linhas): Verifique se a bola colidiu com a raquete. Se houver colisão, inverta (multiplique por -1)
    //  a velocidade horizontal da bola. Para que haja colisão, as seguintes condições devem ser verdadeiras:
    //  - A velocidade horizontal (mVelocity.x) da bola deve ser negativa;
    //  - A distância vertical entra a bola e a raquete deve ser metade da altura da raquete mais
    //    a metade tamanho da bola (mSize/2). Utilize a função (paddle->GetHeight()) para acessar a altura da raquete;
    //  - A posição horizontal da bola (mPosition.x) deve estar entre entre os lados esquerdo e direito da raquete.
    const bool horizontalVelocityIsNegative = mVelocity.x < 0;
    const bool doesHitVertically = verticalDistance <= (paddle->GetHeight() / 2) + (mSize / 2);
    const bool doesHitHorizontally = mPosition.x > paddle->GetPosition().x - paddle->GetWidth() / 2 && mPosition.x < paddle->GetPosition().x + paddle->GetWidth() / 2;
    const bool hasCollided = horizontalVelocityIsNegative && doesHitVertically && doesHitHorizontally;
    if (hasCollided) {
        mVelocity.x *= -1;
    }

    // TODO 3.2.5 (~4 linhas): Verifique se a bola saiu pelo lado esquerdo da tela. Se saiu, finalize o jogo chamando
    //  a função Quit do jogo (GetGame()->Quit()).
    if (mPosition.x <= 0) {
        GetGame()->Quit();
    }

    // TODO 3.2.6 (~4 linhas): Verifique se a bola colidiu com o lado direito da tela. Se houver colisão,
    //  inverta (multiplique por -1) a velocidade horizontal da bola. Para que haja colisão, a velocidade
    //  horizontal da bola (mVelocity.x) deve ser positiva e a posição horizontal da bola (mPosition.x) deve
    //  ser maior do que largura da tela menos a metade do tamanho da bola (mSize/2). Utilize a função
    //  GetGame()->GetWindowWidth() para acessar a largura da tela.
    const bool horizontalVelocityIsPositive = mVelocity.x > 0;
    const bool doesHitRightWall = mPosition.x > wall->GetPosition().x - (wall->GetWidth() / 2) - (mSize / 2);
    if (horizontalVelocityIsPositive && doesHitRightWall) {
        mVelocity.x *= -1;
    }

    // TODO 3.2.7 (~4 linhas): Verifique se a bola colidiu com o limite superior tela. Se houver colisão,
    //  inverta (multiplique por -1) a velocidade vertical da bola. Para que haja colisão, a velocidade
    //  vertical da bola (mVelocity.y) deve ser negativa e a posição vertical da bola (mPosition.y) deve
    //  ser menor ou igual ao limite superior da tela (zero) mais a metade do tamanho da bola (mSize/2).
    const bool verticalVelocityIsNegative = mVelocity.y < 0;
    const bool doesHitTopWall = mPosition.y < 0 + (mSize / 2);
    if (verticalVelocityIsNegative && doesHitTopWall) {
        mVelocity.y *= -1;
    }

    // TODO 3.2.8 (~4 linhas): Verifique se a bola colidiu com o limite inferior da tela. Se houve colisão,
    //  inverta (multiplique por -1) a velocidade vertical da bola. Para que haja colisão, a velocidade
    //  vertical da bola (mVelocity.y) deve ser positiva e a posição vertical da bola (pos.y) deve
    //  ser maior ou igual ao limite inferior da tela (altura) menos a metade do tamanho da bola (mSize/2).
    //  Utilize a função GetGame()->GetWindowHeight() para acessar a altura da tela.
    const bool verticalVelocityIsPositive = mVelocity.y > 0;
    const bool doesHitBottomWall = mPosition.y > GetGame()->GetWindowHeight() - (mSize / 2);
    if (verticalVelocityIsPositive && doesHitBottomWall) {
        mVelocity.y *= -1;
    }

    SetPosition(pos);
}
