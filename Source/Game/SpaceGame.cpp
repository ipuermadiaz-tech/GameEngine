#include "SpaceGame.h"
#include "Engine.h"
#include "Player.h"
#include "Enemy.h"
#include "Assets.h"
using namespace nu;
bool SpaceGame::Initialize()
{
    Game::Initialize();
    m_scene = new Scene();
    m_scene->SetGame(this);
    Engine::Get().GetAudio().AddSound("bass", "bass.wav");
    m_titleFont= new Font();
    m_titleFont->Load("fonts/Handmade_Calligraphy.ttf", 64);
    m_titleText= new Text(m_titleFont);
    m_titleText->Create(Engine::Get().GetRenderer(), "Hello World", Color{ 1.0f, 1.0f, 1.0f });

    m_gameFont = new Font();
    m_gameFont->Load("fonts/Handmade_Calligraphy.ttf", 32);

    m_gameText = new Text(m_gameFont);
    m_liveText = new Text(m_gameFont);
    

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
        SpawnPlayer();
        m_gameState = GameState::StartLevel;

    
        break;
    case GameState::StartLevel:
        m_scene->RemoveAllActors();
        SpawnPlayer();
        m_gameState = GameState::Game;
        break;

    case GameState::Game:
        m_spawnTimer -= dt;
        if (m_spawnTimer <= 0.0f)
        {
            m_spawnTimer = 5.0;

            SpawnEnemy();

        }
      
        break;
    case GameState::GameOver:
        m_gameState = GameState::Title;
        m_scene->RemoveAllActors();
        break;
    
    }

    Game::Update(dt);
}

void SpaceGame::Draw(const nu::Renderer& renderer)
{
    switch (m_gameState) {
    case GameState::Title:
        m_titleText->Draw(renderer, 400, 480);
        break;
    case GameState::StartGame:
        break;
    case GameState::StartLevel:
        break;
    case GameState::Game:
        m_gameText->Create(renderer, "Score:"+std::to_string(m_score), Color{1.0f, 1.0f, 1.0f});
        m_gameText->Draw(renderer, 30, 30);

        m_liveText->Create(renderer, "Lives:" + std::to_string(m_lives), Color{ 1.0f, 1.0f, 1.0f });
        m_liveText->Draw(renderer, 1000, 30);
        break;
    case GameState::GameOver:
        
        break;

    }
    Game::Draw(renderer);

}

void SpaceGame::OnPlayerDead()
{
    m_lives--;
    if (m_lives == 0) m_gameState = GameState::GameOver;
    else m_gameState = GameState::StartLevel;
}

void SpaceGame::SpawnPlayer()
{

    Mesh mesh{ {Vector2{-3.0f, 3.0f}, Vector2{3.0f, 3.0f}, Vector2{0.0f, 0.0f},Vector2{-3.0f, 3.0f}}, Color{255.0f, 255.0f, 255.0f} };
    Mesh mesh2{ {Vector2{-3.0f, 7.0f}, Vector2{3.0f, 3.0f}, Vector2{0.0f, 0.0f},Vector2{-3.0f, 7.0f}}, Color{255.0f, 10.0f, 255.0f} };
    Mesh mesh3{ {Vector2{2.0f, 7.0f}, Vector2{6.0f, 6.0f}, Vector2{0.0f, 0.0f},Vector2{2.0f, 7.0f}}, Color{255.0f, 10.0f, 2.0f} };
    Mesh mesh4{ {Vector2{8.0f, 7.0f}, Vector2{6.0f, 6.0f}, Vector2{2.0f, 2.0f},Vector2{8.0f, 7.0f}}, Color{255.0f, 250.0f, 2.0f} };
    //Mesh mesh4{ {Vector2{-2.0f, 7.0f}, Vector2{6.0f, 6.0f},Vector2{-2.0f, 7.0f}}, Color{705.0f, 102.0f, 2.0f} };
    Model model = std::vector<Mesh>{ mesh,mesh2,mesh3,mesh4 };
    PlayerDesc playerDesc;
    playerDesc.name = "Player";
    playerDesc.tag = "Player";
    playerDesc.speed = 800.0f;
    playerDesc.damping = 2.3f;
    playerDesc.model = model;
    playerDesc.transform = Transform{ Vector2{640.0f,512.0f},0.0f,15.0f };

    Player* player = new Player{ playerDesc };

    m_scene->AddActor(player);
}

void SpaceGame::SpawnEnemy()
{
    Mesh mesh{ {Vector2{-3.0f, 3.0f}, Vector2{3.0f, 3.0f}, Vector2{0.0f, 0.0f},Vector2{-3.0f, 3.0f}}, Color{255.0f, 255.0f, 255.0f} };
    Model model2 = std::vector<Mesh>{ mesh };
    EnemyDesc enemyDesc;
    enemyDesc.name = "Enemy";
    enemyDesc.tag = "Enemy";
    enemyDesc.speed = 800.0f;
    enemyDesc.damping = 3.0f;
    enemyDesc.model = model2;
    enemyDesc.transform = Transform{ Vector2{ru::RandomFloat(1900.0f),ru::RandomFloat(1200.0f)},90.0f,10.0f };

    Enemy* enemy = new Enemy{ enemyDesc };
    m_scene->AddActor(enemy);
}
