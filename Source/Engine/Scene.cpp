#include "Scene.h"
#include "Actor.h"
namespace nu
{
	void Scene::Update(float dt)
	{
		// 1. Flush pending actors into the scene first so they start participating
		if (!m_pendingActors.empty()) {
			m_actors.insert(m_actors.end(), m_pendingActors.begin(), m_pendingActors.end());
			m_pendingActors.clear();
		}

		// 2. Update all actors exactly ONCE
		for (auto actor : m_actors) {
			actor->Update(dt);
		}

		// 3. Resolve collisions
		UpdateCollisions();

		// 4. Clean up destroyed actors
		auto iter = m_actors.begin();
		while (iter != m_actors.end()) {
			if ((*iter)->GetDestroyed()) {
				delete* iter; // Fixed syntax
				iter = m_actors.erase(iter);
			}
			else {
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