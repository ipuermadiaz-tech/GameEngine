#pragma once
#include <vector>
//#include "Actor.h"


#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif
namespace nu
{

	class Actor;
	class ENGINE_API Scene
	{
	public:
		void AddActor(Actor* actor) { m_actors.push_back(actor); }
		void Update(float dt);
		void Draw(const class Renderer& renderer);
	private:
		std::vector<Actor*> m_actors;
   };
}