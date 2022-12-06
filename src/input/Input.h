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
        bool isDown(){
            return isMouseDown;
        }
    protected:
        void mouseDown(SDL_MouseButtonEvent& e);
        void mouseUp(SDL_MouseButtonEvent& e);
        void keyUp();
        void keyDown();
    private:
        Input();
        const Uint8* m_KeyStates; 
        bool isMouseDown = false;
        static Input* s_Instance;
};


#endif