#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../player/GameObject.h"
#include "../map/Map.h"
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
    private:  
        Engine(){}
        bool m_isRunning;
        Map* m_levelMap;
        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;
        static Engine* s_Instance; 
        std::vector<GameObject*> m_gameObjects;
};


#endif