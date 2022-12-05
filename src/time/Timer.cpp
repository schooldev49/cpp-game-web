#include "Timer.h"
#include <SDL2/SDL.h>
#include <iostream>
Timer* Timer::s_Instance = nullptr;

Timer::Timer(){
    if (SDL_Init(SDL_INIT_TIMER) < 0){
        std::cout << SDL_GetError() << "\n";
    }

    lastTimer = 0;
    m_deltaTime = 0;
}

void Timer::Tick(){
    m_deltaTime = (SDL_GetTicks() - lastTimer) * (MAX_FPS); 
    if (m_deltaTime > MAX_DELTA_TIME){
        m_deltaTime = MAX_DELTA_TIME;
    }
    lastTimer = SDL_GetTicks();

}