#pragma once
#include <SDL3/SDL.h>
namespace nu {
	class Renderer
	{
	public:
		bool Initialize(const char* name, int width=1920, int height=1024);
		void Shutdown();

		void SetColor(Uint8 r,Uint8 g,Uint8 b, Uint8 a=255) const;


		void Clear() const;
		void DrawPoint(float x, float y) const;
		void DrawLine(float x1, float y1, float x2, float y2) const;

		void Present();
		void DrawFillRect(float x, float y, float w, float h) const;
		void DrawRect(float x, float y, float w, float h) const;



	private:
		SDL_Window* m_window=nullptr;
		SDL_Renderer* m_renderer = nullptr;
	
	
	
	
	};
}