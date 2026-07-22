#pragma once
#include "Actor.h"
#include "Renderer.h"




struct EnemyDesc : public nu::ActorDesc
{
    float speed = 800.0f;
    int ammo = 0;
};

class Enemy :public nu::Actor
{
public:
    Enemy(const EnemyDesc& enemyDesc)
        : nu::Actor{ enemyDesc }
        , m_speed{ enemyDesc.speed }
        , m_ammo{ enemyDesc.ammo }
    {
    }


    Enemy() = default;
    //Enemy(const EnemyDesc& enemyDesc):
    //    Act

    Enemy(const nu::Transform& transform) : Actor{ transform } {}

    Enemy(const nu::Transform& transform, const nu::Model& model) :
        Actor{ transform,model }


    {
    }
    void Update(float dt) override;
    void Draw(const class nu::Renderer& renderer) const override;

private:
    int m_ammo = 0;
    float m_speed = 800.0f;
};