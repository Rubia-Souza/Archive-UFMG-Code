//
// Created by Lucas N. Ferreira on 03 Aug 23.
//

#include "DrawComponent.h"
#include "../Game.h"

// --------------
// TODO: PARTE 2
// --------------

DrawComponent::DrawComponent(class Actor* owner, int width, int height, int drawOrder)
    :Component(owner)
    ,mDrawOrder(drawOrder)
    ,mWidth(width)
    ,mHeight(height)
{
    // TODO 2.1 (1 linha): Utilize a função AddDrawable do jogo (mOwner->GetGame()) para adicionar esse (this)
    //  componente ao vetor de objetos desenháveis do jogo
    mOwner->GetGame()->AddDrawable(this);
}

DrawComponent::~DrawComponent()
{
    // TODO 2.2 (1 linha): Utilize a função RemoveDrawable do jogo (mOwner->GetGame()) para remover esse (this)
    //  componente ao vetor de objetos desenháveis do jogo
    mOwner->GetGame()->RemoveDrawable(this);
}

void DrawComponent::Draw(SDL_Renderer *renderer)
{
    // TODO 2.3.1 (1 linha): Utilize a função SDL_SetRenderDrawColor para alterar a cor do renderer para branco
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // TODO 2.3.2 (~7 linhas): Crie um retângulo SDL_Rect para representar o objeto visualmente. A posição do retângulo
    //  deve ser o centro do objeto (não o canto esquerdo superior, como originalmente definido pela SDL). Isso
    //  facilitará os cálculos de colisão.
    //  Utilize a função mOwner->GetPosition() para obter a posição original do objeto (canto esquerdo superior)
    //  e os atributos mWidth e mHeight para obter a sua largura e altura respectivamente.
    //  Para deslocar a posição do objeto para o seu centro, subtraia da coordenada x a posição original pela metade da
    //  largura do objeto (mWidth/2) e da coordenada y a metade da altura (mHeight/2). Atribua o resultado dessas
    //  operações como posição final do retângulo criado.
    //  Altura e largura do objeto não precisam ser transformadas.
    const SDL_Rect rectangle = {
        static_cast<int>(mOwner->GetPosition().x) - mWidth / 2,
        static_cast<int>(mOwner->GetPosition().y) - mHeight / 2,
        mWidth,
        mHeight
    };

    // TODO 2.3.3 (1 linha): Desenhe o retângulo criado com a função SDL_RenderFillRect
    SDL_RenderFillRect(renderer, &rectangle);
}
