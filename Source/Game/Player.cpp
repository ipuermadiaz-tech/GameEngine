#include "Player.h"
#include "Renderer.h"
#include "Engine.h"

//struct PlayerDesc: public nu::ActorDesc
//{
//    float speed;
//};

void Player::Update(float dt)
{
   // Player(const PlayerDesc& player)
   // nu::Vector2 force = (0.0f, 0.f);
    float thrust = 0.0f;
    //float speed = 800.0f;
    //if (input.GetButtonPressed(Input::MouseButton::Left)) { std::cout << "button pressed\n"; }
    //if (input.GetButtonReleased(Input::MouseButton::Left)) { std::cout << "button released\n"; }

    //if (nu::g_engine.GetInput().GetKeyDown(SDL_SCANCODE_A)) force.x -= m_speed;
    //if (nu::g_engine.GetInput().GetKeyDown(SDL_SCANCODE_D)) force.x += m_speed;
    //m_speed = 800.0f;
    
        if (nu::Engine::Get().GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust -= m_speed;
    
    if (nu::Engine::Get().GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust += m_speed;




    float rotate = 0.0f;


    if (nu::Engine::Get().GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate -= -180.0f;
    if (nu::Engine::Get().GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate += -180.0f;

    SetRotation(m_transform.rotation + rotate * dt);

    nu::Vector2 forward{ 0,1 };//->
    nu::Vector2 velocity=forward.Rotate(m_transform.rotation*nu::DegToRad)*thrust;
    
        AddVelocity(velocity * dt);




    
    Actor::Update(dt);
}

void Player::Draw(const nu::Renderer& renderer) const
{
	Actor::Draw(renderer);
}
