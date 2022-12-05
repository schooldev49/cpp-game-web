#pragma once

#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL_timer.h>
#include <vector>
const float FPS = 30;
const float MAX_FPS = FPS/1000.0f;
const float MAX_DELTA_TIME = 1.5f;


using TimerID = SDL_TimerID;
using T_Callback = SDL_TimerCallback;
class Timer {
    public:
        Timer();
        void Tick();
        inline float getDeltaTime(){
            return m_deltaTime;
        }
        inline static Timer* GetInstance(){
            return s_Instance = (s_Instance != nullptr)? s_Instance : new Timer();
        }
        inline void Clean(){
            for (TimerID id : m_TimerReg){
                SDL_RemoveTimer(id);
            }
        }
        inline TimerID StartTimer(Uint32 interval, T_Callback callback, void* data){
            TimerID id = SDL_AddTimer(interval,callback,data);
            m_TimerReg.push_back(id);
            return id;
        }

        inline void RemoveTimer(TimerID id){
            SDL_RemoveTimer(id);
        }
    private: 
        static Timer* s_Instance;
        float m_deltaTime;
        float lastTimer;
        std::vector<TimerID> m_TimerReg;

};

#endif