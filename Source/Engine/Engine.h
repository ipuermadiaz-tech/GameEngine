#pragma once
#include "Random.h"
#include "Vector2.h"
#include "Vector3.h"
#include <iostream>
#include <vector>
#include "Input.h"
#include "Renderer.h"
#include "GameTime.h"
#include "Math_Util.h"
#include "Transformer.h"
#include "Actor.h"
#include "Scene.h"

#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif



//void fnEngine();

namespace nu
{
	class ENGINE_API Engine {
	public:
		Engine() = default;
		bool Initialize();
		void ShutDown();
		void Update();
		void Init();

		/////////////////////
		Input& GetInput() { return m_input; }
		Renderer& GetRenderer() { return m_renderer; }
		GameTime& GetTime() { return m_time; }



	private:
		Input m_input;
		Renderer m_renderer;

		GameTime m_time;

	};

	extern ENGINE_API Engine g_engine;

}