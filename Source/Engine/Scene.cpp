#include "Scene.h"
#include "Actor.h"
namespace nu
{
	void Scene::Update(float dt)
	{
		
		for (auto actor : m_actors)
		{
			actor->Update(dt);
		}
		UpdateCollisions();

	}

	void Scene::Draw(const Renderer& renderer)
	{
		for (auto actor : m_actors)
		{
			actor->Draw(renderer);
		}

	}
	void Scene::UpdateCollisions()
	{
		for (auto actorA : m_actors) {

			for (auto actorB : m_actors) {
				if (actorA == actorB || actorA->m_destroyed || actorB->m_destroyed) {
					//()
					continue;
				}
				float distance = (actorA->m_transform.position - actorB->m_transform.position).Length();
				if (distance <= actorA->GetRadious() + actorB->GetRadious()) {
					actorA->OnCollision(actorB);
					actorB->OnCollision(actorA);
				}

			}
		}

	}
	void Scene::AddActor(Actor* actor) {
		actor->m_scene=this;
		m_actors.push_back(actor); 
	}


}