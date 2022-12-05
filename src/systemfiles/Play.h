#pragma once
#ifndef PLAY_H
#define PLAY_H
#include "GameState.h"
#include "Engine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../gui/Label.h"
#include "../map/Map.h"
#include "../player/MainChar.h"
#include "../time/Timer.h"
#include "../input/Input.h"
#include "../viewport/Viewport.h"
#include "../map/MapParser.h"
#include "../gui/Button.h"
#include "../map/MapChunk.h"
#include "../physics/CollisionHandler.h"
#include "../graphics/TextureManager.h"
#include "../systemfiles/ObjectR.h"
class Play : public GameState {
    public:
        Play(){};
        void Events();
        virtual bool Init(std::string mapName = "level1");
        virtual bool Exit();
        virtual void Update();
        virtual void Render();
        static Play* GetInstance(){
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new Play();
        }
        void SetTileMap(Map* mpa){
            if (mpa != nullptr){
                m_LevelMap->Clean();
                m_LevelMap = mpa;
                return;
            }
        }
        static void OpenMenu();
        static void PauseGame();
        bool levelSelector;
        static Play* s_Instance;
        Map* m_LevelMap;
        std::vector<GameObject*> m_gameObjects;
        std::vector<GameObject*> m_guiObjects;
};

#endif