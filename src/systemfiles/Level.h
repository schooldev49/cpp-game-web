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
        void ChangeMap();
        std::string AddLevelStr(bool add);
        static void OpenMenu();
        static void PauseGame();
        std::vector<GameObject*> m_gameObjects;
        std::vector<GameObject*> m_guiObjects;
        Map* m_LevelMap;


    protected: 
        static Level* s_Instance;


};


#endif