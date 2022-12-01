#pragma once

#ifndef TIMER_H
#define TIMER_H

const int FPS = 30;
const float DELTATIME = 1.5f;

class Timer {
    public:
        void Tick();
        inline float getDeltaTime(){
            return m_deltaTime;
        }
        inline static Timer* GetInstance(){
            return s_Instance = (s_Instance != nullptr)? s_Instance : new Timer();
        }
    private: 
        Timer();
        static Timer* s_Instance;
        float m_deltaTime;
        float lastTimer;
};

#endif