// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <SDL_image.h>
#include "CSV.h"
#include "Random.h"
#include "Game.h"
#include "Actors/Actor.h"
#include "Actors/Mario.h"
#include "Actors/Block.h"
#include "Actors/Bricks.h"
#include "Actors/Spawner.h"
#include "Components/DrawComponents/DrawComponent.h"
#include "Components/ColliderComponents/AABBColliderComponent.h"

Game::Game(int windowWidth, int windowHeight)
        :mWindow(nullptr)
        ,mRenderer(nullptr)
        ,mLevelData(nullptr)
        ,mTicksCount(0)
        ,mIsRunning(true)
        ,mUpdatingActors(false)
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

    mWindow = SDL_CreateWindow("TP3: Super Mario Bros", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mWindowWidth, mWindowHeight, 0);
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

    Random::Init();

    mTicksCount = SDL_GetTicks();

    // Init all game actors
    InitializeActors();

    return true;
}

void Game::InitializeActors()
{
    // --------------
    // TODO - PARTE 1
    // --------------

    // TODO 7.1 (~1 linha): Utilize a função LoadLevel para carregar o primeiro nível (Level1.txt) do jogo.
    //  Note que a classe Game tem constantes LEVEL_WIDTH e LEVEL_HEIGHT que definem a largura e altura
    int** levelData = LoadLevel("../Assets/Levels/Level1-1/level1-1.csv", LEVEL_WIDTH, LEVEL_HEIGHT);

    // TODO 7.2 (~4 linhas): Verifique se a matriz de tiles foi carregada corretamente. Se não, retorne.
    //  Se foi, chame a função BuildLevel passando a matriz de tiles, a largura e altura do nível.
    if (levelData == nullptr) {
        return;
    }
    BuildLevel(levelData, LEVEL_WIDTH, LEVEL_HEIGHT);
}

void Game::BuildLevel(int** levelData, int width, int height)
{
    // --------------
    // TODO - PARTE 1
    // --------------

    // TODO 6: Implemente o método BuildLevel para percorrer a matriz de tiles carregada no item anterior e instanciar
    //  game objects para o mario, os canos e os blocos. O Mario deve ser instanciado na posição
    //  correspondente ao tile 16. Os blocos devem ser instanciados na posição correspondente aos tiles
    //  0, 1, 2, 4, 6, 8, 9 e 12. Utilize a função SetPosition para definir a posição de cada game object.
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            switch (levelData[i][j]) {
                case 0: {
                    auto block = new Block(this, "../Assets/Sprites/Blocks/BlockA.png");
                    block->SetPosition(Vector2(j * TILE_SIZE, i * TILE_SIZE));
                    break;
                }
                case 1: {
                    auto block = new Block(this, "../Assets/Sprites/Blocks/BlockC.png");
                    block->SetPosition(Vector2(j * TILE_SIZE, i * TILE_SIZE));
                    break;
                }
                case 2: {
                    auto block = new Block(this, "../Assets/Sprites/Blocks/BlockF.png");
                    block->SetPosition(Vector2(j * TILE_SIZE, i * TILE_SIZE));
                    break;
                }
                case 4: {
                    auto block = new Bricks(this, "../Assets/Sprites/Blocks/BlockB.png", Vector2(j * TILE_SIZE, i * TILE_SIZE));
                    block->SetPosition(Vector2(j * TILE_SIZE, i * TILE_SIZE));
                    break;
                }
                case 6: {
                    auto block = new Block(this, "../Assets/Sprites/Blocks/BlockI.png");
                    block->SetPosition(Vector2(j * TILE_SIZE, i * TILE_SIZE));
                    break;
                }
                case 8: {
                    auto block = new Block(this, "../Assets/Sprites/Blocks/BlockD.png");
                    block->SetPosition(Vector2(j * TILE_SIZE, i * TILE_SIZE));
                    break;
                }
                case 9: {
                    auto block = new Block(this, "../Assets/Sprites/Blocks/BlockH.png");
                    block->SetPosition(Vector2(j * TILE_SIZE, i * TILE_SIZE));
                    break;
                }
                case 10: {
                    auto spawner = new Spawner(this, SPAWN_DISTANCE);
                    spawner->SetPosition(Vector2(j * TILE_SIZE, i * TILE_SIZE));
                    break;
                }
                case 12: {
                    auto block = new Block(this, "../Assets/Sprites/Blocks/BlockG.png");
                    block->SetPosition(Vector2(j * TILE_SIZE, i * TILE_SIZE));
                    break;
                }
                case 16: {
                    mMario = new Mario(this, 2000);
                    mMario->SetPosition(Vector2(j * TILE_SIZE, i * TILE_SIZE));
                }
                default: {
                    continue;
                }
            }
        }
    }


    // --------------
    // TODO - PARTE 5
    // --------------

    // TODO 1: Modifique o método BuildLevel para instanciar spawners na posição correspondente ao tile 10.
    //  Assim como os outros objetos, posicione os spawnwers no mundo conforme as coordenadas i e j na matriz
    //  de tiles. Note que a classe game tem uma constante `SPAWN_DISTANCE = 600` que você pode usar para
    //  configurar a distância de gatilho do spawner.
}

int **Game::LoadLevel(const std::string& fileName, int width, int height)
{
    // --------------
    // TODO - PARTE 1
    // --------------

    // TODO 5: Implemente essa função para carregar o nível a partir do arquivo CSV. Ela deve retornar um
    //  ponteiro para uma matriz 2D de inteiros. Cada linha do arquivo CSV representa uma linha
    //  do nível. Cada número inteiro representa o tipo de bloco que deve ser criado. Utilize a função CSVHelper::Split
    //  para dividir cada linha do arquivo CSV em números inteiros. A função deve retornar nullptr se o arquivo não
    //  puder ser carregado ou se o número de colunas for diferente do esperado.
    std::fstream fout;
    fout.open(fileName, std::ios::in);
    if (!fout.is_open()) {
        return nullptr;
    }

    std::string line;
    int** levelStructure = new int*[height];
    int index = 0;
    while (index < height) {
        levelStructure[index] = new int[width];
        std::getline(fout, line);
        std::vector<int> parsedLine = CSVHelper::Split(line, ',');
        for (int i = 0; i < parsedLine.size(); i++) {
            levelStructure[index][i] = parsedLine[i];
        }
        index++;
    }

    return levelStructure;
}

void Game::RunLoop()
{
    while (mIsRunning)
    {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
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

    const Uint8* state = SDL_GetKeyboardState(nullptr);

    for (auto actor : mActors)
    {
        actor->ProcessInput(state);
    }
}

void Game::UpdateGame()
{
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));

    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
    if (deltaTime > 0.05f)
    {
        deltaTime = 0.05f;
    }

    mTicksCount = SDL_GetTicks();

    // Update all actors and pending actors
    UpdateActors(deltaTime);

    // Update camera position
    UpdateCamera();
}

void Game::UpdateCamera()
{
    // --------------
    // TODO - PARTE 2
    // --------------

    // TODO 1 (~5 linhas): Calcule a posição horizontal da câmera subtraindo metade da largura da janela
    //  da posição horizontal do jogador. Isso fará com que a câmera fique sempre centralizada no jogador.
    //  No SMB, o jogador não pode voltar no nível, portanto, antes de atualizar
    //  a posição da câmera, verifique se a posição horizontal calculada é maior do que a posição horizontal
    //  atual da câmera. Além disso, limite a posição horizontal para que a câmera fique entre 0 e o limite
    //  horizontal máximo do nível. Para calcular o limite horizontal máximo do nível, utilize as constantes
    //  `LEVEL_WIDTH` e `TILE_SIZE`.
    float newHorizontalPosition = mMario->GetPosition().x - mWindowWidth / 2;
    if (newHorizontalPosition < 0) {
        newHorizontalPosition = 0;
    } else if (newHorizontalPosition > LEVEL_WIDTH * TILE_SIZE - mWindowWidth) {
        newHorizontalPosition = LEVEL_WIDTH * TILE_SIZE - mWindowWidth;
    }
    if (newHorizontalPosition > mCameraPos.x) {
        mCameraPos.x = newHorizontalPosition;
    }
}

void Game::UpdateActors(float deltaTime)
{
    mUpdatingActors = true;
    for (auto actor : mActors)
    {
        actor->Update(deltaTime);
    }
    mUpdatingActors = false;

    for (auto pending : mPendingActors)
    {
        mActors.emplace_back(pending);
    }
    mPendingActors.clear();

    std::vector<Actor*> deadActors;
    for (auto actor : mActors)
    {
        if (actor->GetState() == ActorState::Destroy)
        {
            deadActors.emplace_back(actor);
        }
    }

    for (auto actor : deadActors)
    {
        delete actor;
    }
}

void Game::AddActor(Actor* actor)
{
    if (mUpdatingActors)
    {
        mPendingActors.emplace_back(actor);
    }
    else
    {
        mActors.emplace_back(actor);
    }
}

void Game::RemoveActor(Actor* actor)
{
    auto iter = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
    if (iter != mPendingActors.end())
    {
        // Swap to end of vector and pop off (avoid erase copies)
        std::iter_swap(iter, mPendingActors.end() - 1);
        mPendingActors.pop_back();
    }

    iter = std::find(mActors.begin(), mActors.end(), actor);
    if (iter != mActors.end())
    {
        // Swap to end of vector and pop off (avoid erase copies)
        std::iter_swap(iter, mActors.end() - 1);
        mActors.pop_back();
    }
}

void Game::AddDrawable(class DrawComponent *drawable)
{
    mDrawables.emplace_back(drawable);

    std::sort(mDrawables.begin(), mDrawables.end(),[](DrawComponent* a, DrawComponent* b) {
        return a->GetDrawOrder() < b->GetDrawOrder();
    });
}

void Game::RemoveDrawable(class DrawComponent *drawable)
{
    auto iter = std::find(mDrawables.begin(), mDrawables.end(), drawable);
    mDrawables.erase(iter);
}

void Game::AddCollider(class AABBColliderComponent* collider)
{
    mColliders.emplace_back(collider);
}

void Game::RemoveCollider(AABBColliderComponent* collider)
{
    auto iter = std::find(mColliders.begin(), mColliders.end(), collider);
    mColliders.erase(iter);
}

void Game::GenerateOutput()
{
    // Set draw color to black
    SDL_SetRenderDrawColor(mRenderer, 107, 140, 255, 255);

    // Clear back buffer
    SDL_RenderClear(mRenderer);

    for (auto drawable : mDrawables)
    {
        if (drawable->IsVisible())
        {
            drawable->Draw(mRenderer);
        }
    }

    // Swap front buffer and back buffer
    SDL_RenderPresent(mRenderer);
}

SDL_Texture* Game::LoadTexture(const std::string& texturePath) {
    // --------------
    // TODO - PARTE 1
    // --------------

    // TODO 4.1 (~4 linhas): Utilize a função `IMG_Load` para carregar a imagem passada como parâmetro
    //  `texturePath`. Esse função retorna um ponteiro para `SDL_Surface*`. Retorne `nullptr` se a
    //  imagem não foi carregada com sucesso.
    SDL_Surface* surface = IMG_Load(texturePath.c_str());
    if (surface == NULL) {
        SDL_Log("Failed to load texture: %s", SDL_GetError());
        return nullptr;
    }

    // TODO 4.2 (~6 linhas): Utilize a função `SDL_CreateTextureFromSurface` para criar uma textura a partir
    //  da imagem carregada anteriormente. Essa função retorna um ponteiro para `SDL_Texture*`. Logo após criar
    //  a textura, utilize a função `SDL_FreeSurface` para liberar a imagem carregada. Se a textura foi carregada
    //  com sucesso, retorne o ponteiro para a textura. Caso contrário, retorne `nullptr`.
    SDL_Texture* texture = SDL_CreateTextureFromSurface(mRenderer, surface);
    if (texture == NULL) {
        SDL_Log("Failed to create texture: %s", SDL_GetError());
        return nullptr;
    }
    SDL_FreeSurface(surface);

    return texture;
}

void Game::Shutdown()
{
    // Delete actors
    while (!mActors.empty())
    {
        delete mActors.back();
    }

    // Delete level data
    if (mLevelData != nullptr)
    {
        for (int i = 0; i < LEVEL_HEIGHT; ++i)
        {
            if (mLevelData[i] != nullptr)
                delete[] mLevelData[i];
        }
    }
    delete[] mLevelData;

    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}
