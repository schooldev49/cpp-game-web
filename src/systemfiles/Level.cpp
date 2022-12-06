#include "Level.h"
Level* Level::s_Instance = nullptr;

bool Level::Init(std::string mapN){

    std::string mapName = Play::GetInstance()->mapName;
    

    TextureManager::GetInstance()->ParseTexture("assets/textures.tml");
    
    if (!MapParser::GetInstance()->Load(mapName)){
        std::cout << "Unable to load map!";
    }
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
// 138x57 img
   

    /*m_guiObjects.push_back(selectLevelButton);

    m_guiObjects.push_back(settingsButton);*/
    return true;
}

void Level::Render(){
    TextureManager::GetInstance()->Draw("bg",0,0,2100,1050,1,1,0.05);

    m_LevelMap->Render();

    for (auto gameobj : m_gameObjects){
        gameobj->Draw();
    }

    for (auto object : m_guiObjects){
        object->Draw();
    }
    SDL_Rect cam = Viewport::GetInstance()->GetViewBox();

    SDL_RenderCopy(Engine::GetInstance()->GetRenderer(),nullptr,&cam,nullptr);
}

void Level::Update(float dt){
    float dti =  Timer::GetInstance()->getDeltaTime();
    for (auto i : m_gameObjects){
        i->Update(dti);
    }   

    for (auto i : m_guiObjects){
        i->Update(dti);
    }
    Viewport::GetInstance()->Update(dti);
    m_LevelMap->Update();
}

void Level::Events(){

}

bool Level::Exit(){
    delete m_LevelMap;
    for (auto gameobj : m_gameObjects){
        gameobj->Clean();
        delete gameobj;
    }    
    m_gameObjects.clear();
    TextureManager::GetInstance()->Clean();
    return true;
}

void Level::OpenMenu(){
    Engine::GetInstance()->changeState(Menu::GetInstance());
}