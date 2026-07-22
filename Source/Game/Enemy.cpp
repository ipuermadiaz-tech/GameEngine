#include "Enemy.h"
//#include "Renderer.h"
#include "Engine.h"
#include "Player.h"
void Enemy::Update(float dt)
{
    Player* player = m_scene->GetActorByName<Player>("Player");
    if (player)
    {
        nu::Vector2 direction = player->GetTransform().position - m_transform.position;
        float rotation = direction.Angle();
        SetRotation(rotation * nu::RadToDeg);

        nu::Vector2 forward(1, 0);
        forward.Rotate(rotation);
        AddVelocity(forward * m_speed * dt);
    }
    // nu::Vector2 force = (0.0f, 0.f);
    float thrust = 0.0f;
    //float speed = 800.0f;
    //if (input.GetButtonPressed(Input::MouseButton::Left)) { std::cout << "button pressed\n"; }
    //if (input.GetButtonReleased(Input::MouseButton::Left)) { std::cout << "button released\n"; }

    //if (nu::g_engine.GetInput().GetKeyDown(SDL_SCANCODE_A)) force.x -= m_speed;
    float rotate = 0.0f;


   // SetRotation(m_transform.rotation + rotate * dt);

    nu::Vector2 forward{ 1,0 };//->
    nu::Vector2 velocity = forward.Rotate(m_transform.rotation * nu::DegToRad) * thrust;
    AddVelocity(velocity * dt);
    Actor::Update(dt);
}

void Enemy::Draw(const nu::Renderer& renderer) const
{
    Actor::Draw(renderer);
}
