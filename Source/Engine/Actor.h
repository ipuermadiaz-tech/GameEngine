#pragma once
#include "Transformer.h"
#include "Renderer.h"
#include "Math_Util.h"
#include "Model.h"
#include <iostream>

#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

namespace nu
{
    struct ENGINE_API ActorDesc
    {
        std::string name;
        std::string tag;
        Transform transform;
        Vector2 velocity;
        Model model;
    };

    class ENGINE_API Actor

    {

public:
    Actor(const ActorDesc& actorDesc) :
        m_name{ actorDesc.name },
        m_tag{ actorDesc.tag },
        m_transform{ actorDesc.transform },
        m_velocity{ actorDesc.velocity },
        m_model{ actorDesc.model }
    {
    }


     Actor() = default;
    Actor(const Transform& transform) : m_transform{ transform } {}
    Actor(const Transform& transform, const Model& model):
        m_transform{transform},
        m_model{model}
    { }


    //Actor() = default;
    virtual void Update(float dt);

    virtual void Draw(const Renderer& renderer) const;
    const Transform& GetTransform() { return m_transform; }

    void SetPosition(const Vector2& position) { m_transform.position = position; }
    void SetRotation(float rotation) { m_transform.rotation = rotation; }
    void SetScale(float scale) { m_transform.scale = scale; }
    void SetVelocity(Vector2 velocity) { m_transform.velocity = velocity; }
    void AddVelocity(Vector2 velocity) { m_transform.velocity += velocity; }

    Vector2 GetVelocity() { return m_velocity; };
    const Vector2& GetVelocity() const { return m_velocity; }   

   const std::string GetName() const { return m_name; }
   const std::string& GetTag() const { return m_tag; }


protected:
    std::string m_name;
    std::string m_tag;
    Transform m_transform;
    Vector2 m_velocity{ 0,0 };
    Model m_model;
    

};


}
