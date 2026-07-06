//#include <SDL3/SDL.h>

//#include <iostream>
//#include <vector>
#include "Engine.h"
using namespace nu;

int main(int argc, char* argv[]) {

    nu::Renderer renderer;
    renderer.Initialize("Game Engine", 1920, 1024);

    Vector2 vel(0.5f, 0.5f);

   //Vector2 v[300];
    std::vector<Vector2> vect;

    float xs[300];
    float ys[300];

    for (int i = 0;i < 300;i++) {
        xs[i] = ru::RandomFloat(1280);
        ys[i] = ru::RandomFloat(1024);
    }

    SDL_Event event;

    //Main Loop
    bool quit = false;
    while (!quit) {
        //UPDATE
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
        //RENDER
        renderer.SetColor(0, 0, 0);
        renderer.Clear();

        for (int i = 0; i < 300; i++) {
            Vector2 vec{ ru::RandomFloat() ,ru::RandomFloat() };
            vect.push_back(vec);

        }
        for (int i = 0; i < 100; i++) {
            renderer.SetColor(ru::RandomInt(255), ru::RandomInt(255), ru::RandomInt(255));

            //vect[i] = vect[i]+vel;]
           
            //renderer.DrawPoint(vect[i].x, vect[i].y);
            renderer.DrawPoint(ru::RandomInt(1920), ru::RandomInt(1024));
        }

        for (int i = 0; i < 4; i++) {
            renderer.SetColor(rand() % 256, rand() % 256, rand() % 256);
            renderer.DrawFillRect(ru::RandomFloat(1920), ru::RandomFloat(1024), ru::RandomFloat(100), ru::RandomFloat(200));
        }
        for (int i = 0; i < 11; i++) {
            renderer.SetColor(rand() % 256, rand() % 256, rand() % 256);
            renderer.DrawLine(ru::RandomFloat(1920), ru::RandomFloat(1024), ru::RandomFloat(100), ru::RandomFloat(200));
        }


        renderer.Present();
    }
    //SHUTDOWN
    renderer.Shutdown();

    return 0;
}