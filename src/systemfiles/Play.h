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
#include "Menu.h"
#include "../viewport/Viewport.h"
#include "../map/MapParser.h"
#include "../gui/Button.h"
#include "../map/MapChunk.h"
#include "../physics/CollisionHandler.h"
#include "Level.h"
#include "../graphics/TextureManager.h"
#include "../systemfiles/ObjectR.h"
class Play : public GameState {
    public:
        Play(){};
        void Events();
        virtual bool Init(std::string mapName = "level1");
        virtual bool Exit();
        virtual void Update(float dt);
        virtual void Render();
        static Play* GetInstance(){
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new Play();
        }
        bool levelSelector;
        static Play* s_Instance;
        std::vector<GameObject*> m_guiObjects;
        std::string mapName = "level1";
};

#endif