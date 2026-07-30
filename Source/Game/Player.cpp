#include "Player.h"
#include "Renderer.h"
#include "Engine.h"
#include "SpaceGame.h"
#include "Assets.h"
#include "Bullet.h"
//struct PlayerDesc: public nu::ActorDesc
//{
//    float speed;
//};

void Player::Update(float dt)
{
   // Player(const PlayerDesc& player)
   // nu::Vector2 force = (0.0f, 0.f);
    nu::Particle particle;
    particle.position = m_transform.position;
    particle.color = { 255.0f, 222.0f, 222.0f };
    particle.lifespan = ru::RandomFloat(4.0f, 4.5f);
    particle.velocity = { ru::RandomFloat(-200.0f, 200.0f), ru::RandomFloat(-200.0f, 200.0f) };

    nu::Engine::Get().GetPS().AddParticle(particle);


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


        if (nu::Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_SPACE)) {
            BulletDesc desc;
            desc.name = "Bullet";
            desc.tag = "PlayerBullet";
            desc.model = assets::bulletModel;
            desc.transform = m_transform;
            desc.speed = 1000.0f;
           
            //desc.lifespan = 1.0f;

            Bullet* bullet = new Bullet{ desc };

            m_scene->AddActor(bullet);
        }


    
    Actor::Update(dt);
}

void Player::Draw(const nu::Renderer& renderer) const
{
	Actor::Draw(renderer);
}
