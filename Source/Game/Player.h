#pragma once
#include "Actor.h"
#include "Renderer.h"



struct PlayerDesc : public nu::ActorDesc
{
    float speed = 800.0f;
    int ammo = 0;
};
class Player:public nu::Actor
{
public:
    Player(const PlayerDesc& playerDesc)
        : nu::Actor{ playerDesc }   
        , m_speed{ playerDesc.speed }      
        , m_ammo{ playerDesc.ammo }         
    {
    }


    Player() = default;
    Player(const nu::Transform& transform) : Actor{ transform } {}

    Player(const nu::Transform& transform, const nu::Model& model) :
        Actor{transform,model}
    {
    }
    void Update(float dt) override;
    void Draw(const class nu::Renderer& renderer) const override;

private:
	int m_ammo = 0;
    float m_speed = 800.0f;
};