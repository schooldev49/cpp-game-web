#include "Engine.h"
#include "../input/Input.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../graphics/TextureManager.h"
#include "../player/MainChar.h"
#include "../systemfiles/ObjectR.h"
#include "../physics/Transform.h"
#include <SDL2/SDL_ttf.h>
#include "../viewport/Viewport.h"
#include "../map/MapParser.h"
#include "../time/Timer.h"
#include "Play.h"
#include <iostream>

const unsigned int WIDTH = 940, HEIGHT = 640;

Engine* Engine::s_Instance = nullptr;
Play* play = nullptr;

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
    SDL_RendererFlags renderer_flags = (SDL_RendererFlags)(SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) ;
    m_Renderer = SDL_CreateRenderer(m_Window,-1,renderer_flags);
    if (m_Renderer == nullptr){
        std::cout << "unable to create renderer. error: " << SDL_GetError() << "\n";
        return false;
    }

    if (TTF_Init() == -1){
        std::cout << "error while initializing TTF (text). text will not work.\n";
        return false;
    }

    std::cout << "Initializing..\n";
    play = Play::GetInstance();
    std::cout << "Got instance!..\n";
    TextureManager::GetInstance()->AddFont("Comic Sans MS","assets/fonts/comic.ttf",16);
    play->Init();
    std::cout << "Got instancedd!..\n";

    /*m_levelMap = MapParser::GetInstance()->GetMaps("level1");
    MapChunk* cL = (MapChunk*)m_levelMap->GetMapChunks().back();
    CollisionHandler::GetInstance()->SetCollisionMap(cL->GetTileMap(),32);
    TextureManager::GetInstance()->ParseTexture("assets/textures.tml");
    Properties* propChar = new Properties("player",100,200,160,160);
    player = ObjectR::GetInstance()->CreateObject("PLAYER",propChar);
    m_gameObjects.push_back(player);
    Viewport::GetInstance()->SetTarget(player->GetOrigin());*/
    
    return m_isRunning == true;
}

bool Engine::Clean(){
    Timer::GetInstance()->Clean();
    play->Exit();
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
    play->Update();
}

void Engine::Render(){
    play->Render();

}

void Engine::Events(){
    Input::GetInstance()->Listen();

}
