#pragma once

#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

class Input {
    public: 
        static Input* GetInstance(){
            return s_Instance = (s_Instance != nullptr)? s_Instance : new Input();
        }
        void Listen();
        bool getKeyDown(SDL_Scancode key);
    protected:
        void keyUp();
        void keyDown();
    private:
        Input();
        const Uint8* m_KeyStates; 
        static Input* s_Instance;
};


#endif