#include "Engine.h"
#include "../input/Input.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../graphics/TextureManager.h"
#include "../player/MainChar.h"
#include "../physics/Transform.h"
#include "../viewport/Viewport.h"
#include "../map/MapParser.h"
#include "../time/Timer.h"
#include <iostream>

const unsigned int WIDTH = 940, HEIGHT = 640;

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
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);
    m_Window = SDL_CreateWindow("Jumpy game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,window_flags);
    if (m_Window == nullptr){
        std::cout << "unable to create window. error: " << SDL_GetError() << "\n"; 
        return false;
    }
    SDL_RendererFlags renderer_flags = (SDL_RendererFlags)(SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    m_Renderer = SDL_CreateRenderer(m_Window,-1,renderer_flags);
    if (m_Renderer == nullptr){
        std::cout << "unable to create renderer. error: " << SDL_GetError() << "\n";
        return false;
    }

    if (!MapParser::GetInstance()->Load()){
        std::cout << "Unable to load map!";
    }
    
    m_levelMap = MapParser::GetInstance()->GetMaps("level1");

    TextureManager::GetInstance()->ParseTexture("assets/textures.tml");
    player = new MainChar(new Properties("player",100,200,160,160));
    m_gameObjects.push_back(player);
    Viewport::GetInstance()->SetTarget(player->GetOrigin());
    return m_isRunning == true;
}

bool Engine::Clean(){

    for (auto i : m_gameObjects){
        i->Clean();
    }
    TextureManager::GetInstance()->Clean();
    MapParser::GetInstance()->Clean();
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
    float dt = Timer::GetInstance()->getDeltaTime();
    for (auto i : m_gameObjects){
        i->Update(dt);
    }   
    Viewport::GetInstance()->Update(dt);
    m_levelMap->Update();
}

void Engine::Render(){
    SDL_SetRenderDrawColor(m_Renderer,124,218,254,255);
    SDL_RenderClear(m_Renderer);
    //TextureManager::GetInstance()->Draw("rickroll",0,0,1400,1400);
    TextureManager::GetInstance()->Draw("bg",0,0,2100,1050,1,1,0.05);
    m_levelMap->Render();

    for (auto i : m_gameObjects){
        i->Draw();
    }
    SDL_RenderPresent(m_Renderer);

}

void Engine::Events(){
    Input::GetInstance()->Listen();

}