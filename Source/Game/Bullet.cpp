#include "Bullet.h"
#include "Math_Util.h"

void Bullet::Update(float dt)
{
	nu::Vector2 forward{ 0.0f, -1.0f };
	nu::Vector2 velocity = forward.Rotate(m_transform.rotation * nu::DegToRad) * m_speed;

	SetVelocity(velocity);

	Actor::Update(dt);
}