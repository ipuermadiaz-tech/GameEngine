#pragma once
#include "Transformer.h"
#include "Renderer.h"
#include "Math_Util.h"
#include "Model.h"
namespace nu
{
    class Actor

    {

public:
    Actor(const Transform& transform) : m_transform{ transform } {}
    Actor(const Transform& transform, const Model& model):
        m_transform{transform},
        m_model{model}
    { }


    Actor() = default;
    void Update(float dt);

    void Draw(const Renderer& renderer) const;
    const Transform& GetTransform() { return m_transform; }

    void SetPosition(const Vector2& position) { m_transform.position = position; }
    void SetRotation(float rotation) { m_transform.rotation = rotation; }
    void SetScale(float scale) { m_transform.scale = scale; }
    void SetVelocity(Vector2 velocity) { m_transform.velocity = velocity; }
    Vector2 GetVelocity() { return m_velocity; };
    const Vector2& GetVelocity() const { return m_velocity; }




protected:
    Transform m_transform;
    Vector2 m_velocity{ 0,0 };
    Model m_model;
    

};


}
