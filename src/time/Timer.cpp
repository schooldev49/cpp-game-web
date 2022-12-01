#include "Timer.h"
#include <SDL2/SDL.h>

Timer* Timer::s_Instance = nullptr;

Timer::Timer(){
    
}

void Timer::Tick(){
    m_deltaTime = (SDL_GetTicks() - lastTimer) * (FPS/1000.0f); 
    if (m_deltaTime > DELTATIME){
        m_deltaTime = DELTATIME;
    }
    lastTimer = SDL_GetTicks();

}