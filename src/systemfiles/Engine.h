#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../player/GameObject.h"
#include "../map/Map.h"
#include "GameState.h"
#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

class Engine {
    public: 
        static Engine* GetInstance() {
            return s_Instance = (s_Instance != nullptr)? s_Instance : new Engine();
        }
        bool Init();
        bool Clean();
        void Quit();

        void popState();
        void pushState(GameState* current);
        void changeState(GameState* target);
        void Update();
        void Render();
        void Events();
        inline bool isRunning() { 
            return m_isRunning;
        };
        inline SDL_Renderer* GetRenderer(){
            return m_Renderer;
        }

        inline Map* GetMap(){
            return m_levelMap;
        }
        Map* m_levelMap;

        void setRunning(bool run){
            m_isRunning = run;
        }
    protected:  
        Engine(){}
        bool m_isRunning;
        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;
        static Engine* s_Instance; 
        std::vector<GameObject*> m_gameObjects;
        std::vector<GameState*> m_States;
};


#endif