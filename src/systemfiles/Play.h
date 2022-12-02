#pragma once
#ifndef PLAY_H
#define PLAY_H
#include "GameState.h"
#include "Engine.h"
#include <SDL2/SDL.h>
#include "../map/Map.h"
#include "../player/MainChar.h"
#include "../time/Timer.h"
#include "../input/Input.h"
#include "../viewport/Viewport.h"
#include "../map/MapParser.h"
#include "../map/MapChunk.h"
#include "../physics/CollisionHandler.h"
#include "../graphics/TextureManager.h"

class Play : public GameState {
    public:
        Play();
        void Events();
        virtual bool Init();
        virtual bool Exit();
        virtual void Render();
        inline Map* GetMap(){
            return m_LevelMap;
        }
    protected:
        static void OpenMenu();
        static void PauseGame();
        bool levelSelector;
        Map* m_LevelMap;
        std::vector<GameObject*> m_gameObjects;

};

#endif