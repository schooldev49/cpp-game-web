#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1250
#define SCREEN_HEIGHT 350

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
    private:  
        Engine(){}
        bool m_isRunning;
        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;
        static Engine* s_Instance; 
};


#endif