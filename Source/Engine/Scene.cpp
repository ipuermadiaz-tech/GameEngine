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

		// add pending actors
		m_actors.insert(m_actors.end(), m_pendingActors.begin(), m_pendingActors.end());
		m_pendingActors.clear();
		UpdateCollisions();


		auto iter = m_actors.begin();
		while (iter != m_actors.end())
		{
			if ((*iter)->GetDestroyed())
			{
				delete* iter;               // Free memory
				iter = m_actors.erase(iter); // Remove pointer from vector
			}
			else
			{
				(*iter)->Update(dt);
				++iter;
			}
		}
	}

	void Scene::Draw(const Renderer& renderer)
	{
		for (auto actor : m_actors)
		{
			actor->Draw(renderer);
		}

	}
	void Scene::RemoveAllActors()
	{
		for (auto actor : m_actors)
		{
			delete actor;
		}
		m_actors.clear();

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
		m_pendingActors.push_back(actor);
	}


}