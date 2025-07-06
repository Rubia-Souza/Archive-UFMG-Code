// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include <algorithm>
#include "Game.h"
#include "Actors/Actor.h"
#include "Actors/Paddle.h"
#include "Actors/Wall.h"
#include "Components/DrawComponent.h"

Game::Game(int windowWidth, int windowHeight)
        :mWindow(nullptr)
        ,mRenderer(nullptr)
        ,mTicksCount(0)
        ,mIsRunning(true)
        ,mUpdatingActors(false)
        ,mPaddle(nullptr)
        ,mBall(nullptr)
        ,mWindowWidth(windowWidth)
        ,mWindowHeight(windowHeight)
{

}

bool Game::Initialize()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    mWindow = SDL_CreateWindow("P2: Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mWindowWidth, mWindowHeight, 0);
    if (!mWindow)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!mRenderer)
    {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return false;
    }

    // --------------
    // TODO - PARTE 1
    // --------------

    // TODO 1.1 (1 linha): Utilize a função SDL_GetTicks() para inicializar o atributo mTicksCount, de tal forma que ele
    //  represente o tempo (em milissegundos) decorrido desde a inicialização da SDL (1 linha).
    //  Ver documentação da SDL_GetTicks: https://wiki.libsdl.org/SDL2/SDL_GetTicks
    mTicksCount = SDL_GetTicks();

    // Init all game actors
    InitializeActors();

    return true;
}

void Game::RunLoop()
{
    // --------------
    // TODO: PARTE 1
    // --------------

    // TODO 1.2 (~6 linhas): Escreva um laço while que é executado enquanto o atributo `mIsRunning` for verdadeiro.
    //  Dentro do laço, execute os métodos `ProcessInput`, `UpdateGame` e `GenerateOutput` nessa ordem
    while (mIsRunning) {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::UpdateGame()
{
    // --------------
    // TODO: PARTE 1
    // --------------

    // TODO 1.3.1 (1 linha): Utilize a função SDL_TICKS_PASSED em um loop while para garantir que pelo menos
    //  16 milissegundos tenham se passado desde o último quadro. Lembre-se que o a variável mTicksCount armazena
    //  o tempo de término do último quadro.
    //  Ver documentação da SDL_TICKS_PASSED: https://wiki.libsdl.org/SDL2/SDL_TICKS_PASSED
    while(!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16)) {}

    // TODO 1.3.2 (1 linha): Utilize a função SDL_GetTicks() para obter o tempo (em ms) decorrido até o quadro atual
    //  e subtraia por mTicksCount, obtendo o tempo (em ms) entre o quadro atual e o passado. Converta o resultado para segundos
    //  e armazene o resultado em uma variável do tipo float chamada deltaTime
    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;

    // TODO 1.3.3 (~4 linhas): Verifique se deltaTime é superior a 0.05 segundos e, se for, limite-a para 0.05 segundos
    if (deltaTime > 0.05f) {
        deltaTime = 0.05f;
    }

    // TODO 1.3.4 (1 linha): Utilize a função SDL_GetTicks para atualizar o contador de tempo mTicksCount
    mTicksCount = SDL_GetTicks();

    // TODO 1.3.5 (1 linha): Chame a função UpdateActors(deltaTime) para atualizar os objetos do jogo
    UpdateActors(deltaTime);
}

void Game::UpdateActors(float deltaTime)
{
    // --------------
    // TODO - PARTE 2
    // --------------

    // TODO 2.1.1 (~6 linhas): Atribua verdadeiro para mUpdatingActors e, em seguida, escreva um laço para percorrer
    //  todos os elementos do vetor mActors, chamando a função Update(deltaTime) para cada um deles.
    //  Ao final do laço, atribua falso para mUpdatingActors.
    mUpdatingActors = true;
    for (Actor* actor : mActors) {
        actor->Update(deltaTime);
    }
    mUpdatingActors = false;

    // TODO 2.1.2 (~6 linhas): Escreva um laço *for* para percorrer todos os elementos do vetor mPendingActors,
    //  adicionando-os ao final do vetor mActors. Após o laço, remova todos os elementos de mPendingActors.
    for (Actor* pendingActor : mPendingActors) {
        mActors.push_back(pendingActor);
    }
    mPendingActors.clear();

    // TODO 2.1.3 (~8 linhas): Crie um vetor chamado deadActors para armazenar ponteiros para os objetos a serem destruídos. Depois,
    //  escreva um laço for para percorrer todos os elementos do vetor mActors, adicionando os que estivem no estado
    //  ActorState::Destroy ao final de deadActors.
    std::vector<class Actor*> deadActors;
    for (Actor* actor : mActors) {
        if (actor->GetState() == ActorState::Destroy) {
            deadActors.push_back(actor);
        }
    }

    // TODO 2.1.4 (~4 linhas): Escreva um laço *for* para percorrer todos os elementos do vetor deadActors e
    //  removê-los um a um
    for (Actor* actor : deadActors) {
        RemoveActor(actor);
    }
    deadActors.clear();

}

void Game::AddActor(Actor* actor)
{
    // --------------
    // TODO - PARTE 2
    // --------------

    // TODO 2.2 (~8 linhas): verifique se o jogo está atualizando objetos (mUpdatingActors == true). Se estiver,
    //  adicione o novo objeto (actor) ao final do vetor mPendingActors. Se não, ao final de mActors
    if (mUpdatingActors) {
        mPendingActors.push_back(actor);
    } else {
        mActors.push_back(actor);
    }

}

void Game::RemoveActor(Actor* actor)
{
    // --------------
    // TODO - PARTE 2
    // --------------

    // TODO 2.3.1 (~7 linhas): Utilize a função std::find para procurar pelo objeto a ser removido no vetor de objetos
    //  pendentes (mPendingActors). Se encontrar, utilize a função std::iter_swap para trocar o objeto encontrado de
    //  posição com o último elemento de mPendingActors. Em seguida, remova o último elemento de mPendingActors com
    //  a função pop_back. Não utilize o delete para remover o elemento encontrado pois isso irá gerar um loop infinito.
    auto iteratorPendingActors = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
    if (iteratorPendingActors != mPendingActors.end()) {
        std::iter_swap(iteratorPendingActors, mPendingActors.end());
        mPendingActors.pop_back();
    }

    // TODO 2.3.2 (~7 linhas): Utilize a função std::find para procurar pelo objeto a ser removido no vetor de objetos
    //  ativos (mActors). Se encontrar, utilize a função std::iter_swap para trocar o objeto encontrado de
    //  posição com o último elemento de mActors. Em seguida, remova o último elemento de mActors com a função pop_back.
    //  NÃO utilize o delete para remover o elemento encontrado pois isso irá gerar um loop infinito.
    auto iteratorActors = std::find(mActors.begin(), mActors.end(), actor);
    if (iteratorActors != mActors.end()) {
        std::iter_swap(iteratorActors, mActors.end());
        mActors.pop_back();
    }
}

void Game::AddDrawable(class DrawComponent *drawable)
{
    // --------------
    // TODO - PARTE 2
    // --------------

    // TODO 2.4.1 (1 linha): adicione o novo componente (drawable) ao final do vetor de componentes visuais (mDrawables)
    mDrawables.push_back(drawable);

    // TODO 2.4.2 (~5 linha): ordene (std::sort) de forma crescente o vetor de componentes visuais (mDrawables) de acordo com
    //  a prioridade (GetDrawOrder()) estabelecida na criação do componente
    std::sort(mDrawables.begin(), mDrawables.end(), [](const DrawComponent* component1, const DrawComponent* component2) {
        return component1->GetDrawOrder() < component2->GetDrawOrder();
    });

}

void Game::RemoveDrawable(class DrawComponent *drawable)
{
    // --------------
    // TODO - PARTE 2
    // --------------

    // TODO 2.5 (2 linhas): procure (std::find) pelo componente dado (drawable) no vetor de componentes
    //  visuais (mDrawables) e o remova (erase) desse vetor
    auto iteratorDrawable = std::find(mDrawables.begin(), mDrawables.end(), drawable);
    mDrawables.erase(iteratorDrawable);
}

void Game::ProcessInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                Quit();
                break;
        }
    }

    // --------------
    // TODO: PARTE 2
    // --------------

    // TODO 2.6.1 (~1 linha): Utilize a função SDL_GetKeyboardState para acessar o estado do jogo. Salve o estado em
    //  uma constante Uint8* state.
    const Uint8* state = SDL_GetKeyboardState(nullptr);

    // TODO 2.6.2 (~4 linhas): Percorra o vetor de objetos (mActors), chamando a função ProcessInput(state)
    //  para cada um deles.
    for (Actor* actor : mActors) {
        actor->ProcessInput(state);
    }

}

void Game::GenerateOutput()
{
    // Set draw color to white
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);

    // Clear back buffer
    SDL_RenderClear(mRenderer);

    // --------------
    // TODO - PARTE 2
    // --------------

    // TODO 2.7 (~4 linhas): percorra o vetor de componentes visuais (mDrawables) e chame a função Draw(mRenderer)
    //  para cada um deles.
    for (DrawComponent* drawable : mDrawables) {
        drawable->Draw(mRenderer);
    }

    // Swap front buffer and back buffer
    SDL_RenderPresent(mRenderer);
}

void Game::Shutdown()
{
    // --------------
    // TODO - PARTE 2
    // --------------

    // TODO 2.8 (~4 linhas): percorra o vetor de objetos (mActors) enquanto (while) ele tiver elementos
    //  (!mActors.empty()), deletando (delete) o último elemento do vetor mActors.back(). É necessário
    //  usar um laço *while* pois o *for* deve percorrer por índices e estes seriam desconfigurados no
    //  momento da remoção (delete).
    while (!mActors.empty()) {
        delete mActors.back();
    }

    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Game::InitializeActors()
{
    // --------------
    // TODO - PARTE 3
    // --------------

    // TODO 3.1 (~2 linhas): Instancie a raquete mPaddle e inicialize sua posição com o método SetPosition
    mPaddle = new Paddle(this);
    mPaddle->SetPosition(Vector2(50, mWindowHeight / 2.0));

    // TODO 3.2 (~3 linhas): Instancie a bola mBall e inicialize sua posição e velocidade com os métodos
    //  SetPosition e SetVelocity, respectivamente
    mBall = new Ball(this);
    mBall->SetPosition(Vector2(mWindowWidth / 2.0,mWindowHeight / 2.0));
    mBall->SetVelocity(Vector2(500, 100));

    mWall = new Wall(this);
    mWall->SetPosition(Vector2(mWindowWidth - mWall->GetWidth() / 2, mWall->GetHeight() / 2));
}
