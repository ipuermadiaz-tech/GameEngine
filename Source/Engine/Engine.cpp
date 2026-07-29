//miau
#include "Engine.h"
//#include "framework.h"
#include <iostream>

namespace nu
{
	//Engine g_engine;

	bool Engine::Initialize()
	{
		m_renderer.Initialize("Game Engine", 1920, 1024);
	    m_input.Initialize();
		return true;


	}
	void Engine::ShutDown(){
		m_input.Shutdown();
		m_renderer.Shutdown();
	}
	void Engine::Update()
	{
		m_input.Update();
		m_time.Tick();
	}

}