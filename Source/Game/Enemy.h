#pragma once
#include "Actor.h"
#include "Renderer.h"
class Enemy :public nu::Actor
{
public:
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