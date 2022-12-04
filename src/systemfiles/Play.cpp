#include "Play.h"
#include "Menu.h"
#include <SDL2/SDL.h>
Play* Play::s_Instance = nullptr;





bool Play::Init(std::string mapName){
    levelSelector = false;
    m_Ctxt = Engine::GetInstance()->GetRenderer();

    TextureManager::GetInstance()->ParseTexture("assets/textures.tml");
    m_LevelMap = MapParser::GetInstance()->GetMaps(mapName);
    MapChunk* collisionLayer = (MapChunk*)m_LevelMap->GetMapChunks().back();
    CollisionHandler::GetInstance()->SetCollisionMap(collisionLayer->GetTileMap(),32);

    int tSize = 32;
    int width = collisionLayer->GetWidth()*tSize;
    int height = collisionLayer->GetHeight()*tSize;

    Viewport::GetInstance()->SetSceneLimit(width,height);
    Properties* propChar = new Properties("player",100,200,160,160);
    MainChar* player = new MainChar(propChar);
    m_gameObjects.push_back(player);
    Viewport::GetInstance()->SetTarget(player->GetOrigin());
    return true;
   // m_LevelMap = MapParser::GetInstance()->Load("assets/maps/map.tmx");

}

void Play::Render(){
    SDL_SetRenderDrawColor(m_Ctxt,124,218,254,255);
    SDL_RenderClear(m_Ctxt);
    TextureManager::GetInstance()->Draw("bg",0,0,2100,1050,1,1,0.05);

    m_LevelMap->Render();

    for (auto gameobj : m_gameObjects){
        gameobj->Draw();
    }

    SDL_Rect cam = Viewport::GetInstance()->GetViewBox();
    if (levelSelector){

    }

    SDL_RenderCopy(m_Ctxt,nullptr,&cam,nullptr);
    SDL_RenderPresent(m_Ctxt);
}

void Play::Update(){
    Events();

    if (!levelSelector){
        float dt =  Timer::GetInstance()->getDeltaTime();
        for (auto i : m_gameObjects){
            i->Update(dt);
        }   
        Viewport::GetInstance()->Update(dt);
        m_LevelMap->Update();
    }
}

void Play::Events(){

}

bool Play::Exit(){
    delete m_LevelMap;
    for (auto gameobj : m_gameObjects){
        gameobj->Clean();
        delete gameobj;
    }    
    m_gameObjects.clear();
    TextureManager::GetInstance()->Clean();
    return true;
}

void Play::OpenMenu(){
    Engine::GetInstance()->changeState(new Menu());
}