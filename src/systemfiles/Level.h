#pragma once

#ifndef LEVEL_H
#define LEVEL_H

#include "GameState.h"
#include "Play.h"
class Level : public GameState {
    public:
        Level(){};
        void Events();
        virtual bool Init(std::string mapName = "level1");
        virtual bool Exit();
        virtual void Update(float dt);
        virtual void Render();
        static Level* GetInstance(){
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new Level();
        }
        void ChangeMap(std::string mapID){
            if (mapID != ""){
                m_LevelMap->Clean();
                if (!MapParser::GetInstance()->Load(mapID)){
                    std::cout << "Unable to load map!";
                }
                m_LevelMap = MapParser::GetInstance()->GetMaps(mapID);
                MapChunk* collisionLayer = (MapChunk*)m_LevelMap->GetMapChunks().back();
                CollisionHandler::GetInstance()->SetCollisionMap(collisionLayer->GetTileMap(),32);

                int tSize = 32;
                int width = collisionLayer->GetWidth()*tSize;
                int height = collisionLayer->GetHeight()*tSize;

                Viewport::GetInstance()->SetSceneLimit(width,height);
              
                return;
            }
        }
        static void OpenMenu();
        static void PauseGame();
        std::vector<GameObject*> m_gameObjects;
        std::vector<GameObject*> m_guiObjects;

        Map* m_LevelMap;


    protected: 
        static Level* s_Instance;


};


#endif