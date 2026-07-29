#include "SpaceGame.h"
#include "Engine.h"
#include "Assets.h"
using namespace nu;
bool SpaceGame::Initialize()
{
    Game::Initialize();
    m_scene = new Scene();
    return true;
}

void SpaceGame::Update(float dt)
{
    switch (m_gameState) {
    case GameState::Title:
        if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_SPACE))
        {
            m_gameState = GameState::StartGame;
        }
        break;
    case GameState::StartGame:
        m_score = 0;
        m_lives = 3;
        m_gameState = GameState::StartLevel;
    
        break;
    case GameState::StartLevel:
        break;
    case GameState::Game:
        break;
    case GameState::GameOver:
        break;
    
    }

    Game::Update(dt);
}

void SpaceGame::Draw(const nu::Renderer& renderer)
{
    switch (m_gameState) {
    case GameState::Title:
        break;
    case GameState::StartGame:
        break;
    case GameState::StartLevel:
        break;
    case GameState::Game:
        break;
    case GameState::GameOver:
        break;

    }
    Game::Draw(renderer);

}
