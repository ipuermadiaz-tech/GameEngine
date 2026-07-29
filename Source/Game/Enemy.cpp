#include "Enemy.h"
//#include "Renderer.h"
#include "Engine.h"
#include "Player.h"
void Enemy::Update(float dt)
{
    if (upndown) {
        if (m_counter <= 1280) {
            m_counter++;
        }
        else {
            upndown = false;
        }
        
    }
    else {
        if (m_counter >= -1280) {
            m_counter--;
        }
        else {
            upndown = true;
        }
    }
    Player* player = m_scene->GetActorByName<Player>("Player");
    if (player)
    {
        nu::Vector2 direction = player->GetTransform().position - m_transform.position;
        float rotation = direction.Angle();
        SetRotation(rotation * nu::RadToDeg);

        //nu::Vector2 forward(1, 0);
        //forward.Rotate(rotation);
        //if (upndown) {
        //    AddVelocity(forward * m_speed * dt);
        //}
        //else {
        //    SubstractVelocity(forward * m_speed * dt);
        //}
    }
    
   // SetRotation(m_transform.rotation + rotate * dt);

    nu::Vector2 forward{ 1,0 };//->
    nu::Vector2 velocity = forward.Rotate(m_transform.rotation * nu::DegToRad) * m_speed;
    AddVelocity(velocity * dt);
    Actor::Update(dt);
}

void Enemy::OnCollision(Actor* other)
{
    if (other->GetName() == "player") {
        SetDestroyed();
    
    }
}

void Enemy::Draw(const nu::Renderer& renderer) const
{
    
    Actor::Draw(renderer);
}
