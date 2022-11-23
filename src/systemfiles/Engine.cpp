#include "Engine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../graphics/TextureManager.h"
#include "../player/MainChar.h"
#include "../physics/Transform.h"
#include <iostream>

const unsigned int WIDTH = 800, HEIGHT = 600;

Engine* Engine::s_Instance = nullptr;
MainChar* player = nullptr;
/*
 bool Init();
        bool Clean();
        void Quit();
        void Update();
        void Render();
        void Events();
*/
bool Engine::Init(){
    m_Window = SDL_CreateWindow("Jumpy game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_ALLOW_HIGHDPI);
    if (m_Window == nullptr){
        std::cout << "unable to create window. error: " << SDL_GetError() << "\n"; 
        return false;
    }

    m_Renderer = SDL_CreateRenderer(m_Window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_Renderer == nullptr){
        std::cout << "unable to create renderer. error: " << SDL_GetError() << "\n";
        return false;
    }
    m_isRunning = true;
    TextureManager::GetInstance()->Load("player","assets/rickroll.png");
    player = new MainChar(new Properties("player",100,200,1000,1000));
    return m_isRunning == true;
}

bool Engine::Clean(){
    TextureManager::GetInstance()->Clean();
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
    IMG_Quit();
    return true;
}

void Engine::Quit() {
    m_isRunning = false;
}

void Engine::Update() {
    player->Update(0);
}

void Engine::Render(){
    SDL_SetRenderDrawColor(m_Renderer,124,218,254,255);
    SDL_RenderClear(m_Renderer);
    //TextureManager::GetInstance()->Draw("rickroll",0,0,1400,1400);
    player->Draw();
    SDL_RenderPresent(m_Renderer);

}

void Engine::Events(){
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type){
        case SDL_QUIT:
            Quit();
            break;

    }
}