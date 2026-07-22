#include <SDL3/SDL.h>
#include "Enemy.h"
//#include <iostream>
//#include <vector>
#include "Engine.h"
#include "Player.h"
#include "Main.h"
#include <fmod.hpp>




using namespace nu;




int main(int argc, char* argv[]) {
   Engine engine;
    g_engine.Initialize();

    FMOD::System* audio;
    FMOD::System_Create(&audio);

    void* extradriverdata = nullptr;
    audio->init(32, FMOD_INIT_NORMAL, extradriverdata);
    std::vector<FMOD::Sound*> sounds;

    FMOD::Sound* sound = nullptr;
    audio->createSound("clap.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);
   

     sound = nullptr;
    audio->createSound("cowbell.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    sound = nullptr;
    audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    sound = nullptr;
    audio->createSound("bass.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);
    sound = nullptr;
    audio->createSound("close-hat.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);





   

    union
    {
        struct { float x, y, z; };
        struct { float r, g, b; };
    };

    nu::Renderer renderer;
    //renderer.Initialize("Game Engine", 1920, 1024);
    //g_engine.Initialize();


    Vector2 velocity(0.0f, 0.0f);
    Vector2 position{ 640,512 };
    float speed = 400.0f;
    
    Scene scene;

    // mesh/Model
    Mesh mesh{ {Vector2{-3.0f, 3.0f}, Vector2{3.0f, 3.0f}, Vector2{0.0f, 0.0f},Vector2{-3.0f, 3.0f}}, Color{255.0f, 255.0f, 255.0f} };
    Mesh mesh2{ {Vector2{-3.0f, 7.0f}, Vector2{3.0f, 3.0f}, Vector2{0.0f, 0.0f},Vector2{-3.0f, 7.0f}}, Color{255.0f, 10.0f, 255.0f} };
    Mesh mesh3{ {Vector2{2.0f, 7.0f}, Vector2{6.0f, 6.0f}, Vector2{0.0f, 0.0f},Vector2{2.0f, 7.0f}}, Color{255.0f, 10.0f, 2.0f} };
    Mesh mesh4{ {Vector2{8.0f, 7.0f}, Vector2{6.0f, 6.0f}, Vector2{2.0f, 2.0f},Vector2{8.0f, 7.0f}}, Color{255.0f, 250.0f, 2.0f} };
    //Mesh mesh4{ {Vector2{-2.0f, 7.0f}, Vector2{6.0f, 6.0f},Vector2{-2.0f, 7.0f}}, Color{705.0f, 102.0f, 2.0f} };
    Model model = std::vector<Mesh>{ mesh,mesh2,mesh3,mesh4 };
    Model model2 = std::vector<Mesh>{ mesh };
    //Player
    Player* player= new Player{Transform{Vector2{640.0f,512.0f},0.0f,15.0f}, model};
   
    //Actor player{Transform{Vector2{640.0f,512.0f}}
   // Mesh mesh{ {Vector2{-3,3},Vector2{3,3},Vector2{0,0},Color{0.0,0.0,0.0}} };
   // Actor player{ Transform{Vector2{640.0f,512.0f},0.0f,50.0f} };
    scene.AddActor(player);
    for (int i = 0;i < 20;i++) {
        Enemy* enemy = new Enemy{ Transform{Vector2{ru::RandomFloat(1900.0f),ru::RandomFloat(1200.0f)},90.0f,10.0f}, model2 };
        scene.AddActor(enemy);

    };

   





    //Actor player{ Transform{Vector2{640.0f,512.0f},0.0f,50.0f} };

	nu::Input input;


   //Vector2 v[300];
    std::vector<Vector2> points;

    float xs[300];
    float ys[300];

    for (int i = 0;i < 300;i++) {
        xs[i] = ru::RandomFloat(1280);
        ys[i] = ru::RandomFloat(1024);
    }
	//engine 
    SDL_Event event;

    uint64_t ticks = SDL_GetTicksNS();
    uint64_t prevticks=ticks;

    //Main Loop
    bool quit = false;
    	//input.Initialize();
    while (!quit) {
        //UPDATE
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = true;
            }
            if (event.type == SDL_EVENT_KEY_DOWN&&event.key.scancode == SDL_SCANCODE_ESCAPE){
                quit=true;
            }
       }
        //emgome
        g_engine.Update();
        if (g_engine.GetInput().GetKeyPressed(SDL_SCANCODE_1))
        {
            audio->playSound(sounds[0], nullptr, false, nullptr);
        }

        if (g_engine.GetInput().GetKeyPressed(SDL_SCANCODE_2))
        {
            audio->playSound(sounds[1], nullptr, false, nullptr);
        }
        else if (g_engine.GetInput().GetKeyPressed(SDL_SCANCODE_3))
        {
            audio->playSound(sounds[2], nullptr, false, nullptr);
        }
        else if (g_engine.GetInput().GetKeyPressed(SDL_SCANCODE_4))
        {
            audio->playSound(sounds[3], nullptr, false, nullptr);
        }
        else if (g_engine.GetInput().GetKeyPressed(SDL_SCANCODE_5))
        {
            audio->playSound(sounds[4], nullptr, false, nullptr);
        }

        audio->update();

     




		//input.Update();


        prevticks = ticks;
        ticks = SDL_GetTicksNS();

        

        float seconds = (float)ticks / 1'000'000'000;
        float dt = (float)(ticks - prevticks) / 1'000'000'000;

        //player.SetRotation(player.GetTransform().rotation + (90.0f*dt));
        //player.SetRotation(90.0f);

        //std::cout << seconds << std::endl;
       
        ///
		//if (input.GetKeyPressed(SDL_SCANCODE_Q)) std::cout << "Q Pressed" << std::endl;
  //      if (input.GetKeyDown(SDL_SCANCODE_Q)) std::cout << "Q Down" << std::endl;
  //      if (input.GetKeyReleased(SDL_SCANCODE_Q)) std::cout << "Q Released" << std::endl;
        //int numkeys;
        //const bool * keystate = SDL_GetKeyboardState(&numkeys);
		//if (keystate[SDL_SCANCODE_SPACE]) std::cout << "Space Pressed" << std::endl;

		Vector2 mousePosition;
		SDL_GetMouseState(&mousePosition.x, &mousePosition.y);

      
        Vector2 force = (0.0f,0.f);

        //if (input.GetButtonPressed(Input::MouseButton::Left)) { std::cout << "button pressed\n"; }
        //if (input.GetButtonReleased(Input::MouseButton::Left)) { std::cout << "button released\n"; }

        //if (input.GetKeyDown(SDL_SCANCODE_A)) force.x -= speed;
        //if (input.GetKeyDown(SDL_SCANCODE_D)) force.x += speed;
        //if (input.GetKeyDown(SDL_SCANCODE_W)) force.y -= speed;
        //if (input.GetKeyDown(SDL_SCANCODE_S)) force.y += speed;


        //player.SetVelocity(player.GetVelocity() + force * dt);
        //player.Update(dt);

        

        velocity += (force * dt);
        position += (velocity * dt);


        position.x = Wrap(0.0f, 1920.0f, position.x);

        position.y = Wrap(0.0f, 1024.0f, position.y);

        //if (position.x > 10) position.x = 0;
        //if (position.x < 0) position.x = 1279;

        //RENDER
        g_engine.GetRenderer().SetColor(0, 0, 0);
       
        //g_engine.GetRenderer().DrawFillRect(position.x, position.y, 50, 50);

        //for (int i = 0; i < 300; i++) {
        //    Vector2 vec{ ru::RandomFloat() ,ru::RandomFloat() };
        //    points.push_back(vec);

        //}
        //for (int i = 0; i < 100; i++) {
        //    renderer.SetColor(ru::RandomInt(255), ru::RandomInt(255), ru::RandomInt(255));

        //    //vect[i] = vect[i]+vel;]
        //   
        //    //renderer.DrawPoint(vect[i].x, vect[i].y);
        //    renderer.DrawPoint(ru::RandomInt(1920), ru::RandomInt(1024));
        //}

        for (int i = 0; i < points.size(); i++) {
            g_engine.GetRenderer().SetColor(ru::RandomInt(255), ru::RandomInt(255), ru::RandomInt(255));

            //points[i] = points[i];

            g_engine.GetRenderer().DrawPoint(points[i].x, points[i].y);
          
        }
        //if(input.GetButtonPressed(Input::MouseButton::Left))
        //{
        //    points.push_back(input.GetMousePosition());
        //}
        //player.Update(dt);
        //enemy.Update(dt);
        scene.Update(dt);
        //if (g_engine.GetInput().GetButtonDown(Input::MouseButton::Left))
        //{
        //    if (points.empty())
        //    {
        //        points.push_back(g_engine.GetInput().GetMousePosition());
        //    }

        //           Vector2 v= points.back()- g_engine.GetInput().GetMousePosition();
        //  if (v.Length() > 10.0f) {
        //      points.push_back(g_engine.GetInput().GetMousePosition());
        //  }
        //}

        //if (!points.empty()) {
        //    for (size_t i = 0;i < points.size() - 1;i++) {
        //        g_engine.GetRenderer().SetColor(ru::RandomInt(255), ru::RandomInt(255), ru::RandomInt(255));
        //        g_engine.GetRenderer().DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);

        //    }
        //}
        if (g_engine.GetInput().GetButtonPressed(Input::MouseButton::Right))
        {
            if (!points.empty()) { points.pop_back(); }

        }


        

        //character
        
            

        //for (int i = 0; i < 4; i++) {
        //    renderer.SetColor(rand() % 256, rand() % 256, rand() % 256);
        //    renderer.DrawFillRect(ru::RandomFloat(1920), ru::RandomFloat(1024), ru::RandomFloat(100), ru::RandomFloat(200));
        //}
        //for (int i = 0; i < 11; i++) {
        //    renderer.SetColor(rand() % 256, rand() % 256, rand() % 256);
        //    renderer.DrawLine(ru::RandomFloat(1920), ru::RandomFloat(1024), ru::RandomFloat(100), ru::RandomFloat(200));
        //}

        g_engine.GetRenderer().Clear();



        g_engine.GetRenderer().SetColor(255.0f, 255.0f, .0f);

        //player.Draw(g_engine.GetRenderer());
        //enemy.Draw(g_engine.GetRenderer());
        scene.Draw(g_engine.GetRenderer());


        g_engine.GetRenderer().Present();
    }
    //SHUTDOWN
    g_engine.ShutDown();

    return 0;
}