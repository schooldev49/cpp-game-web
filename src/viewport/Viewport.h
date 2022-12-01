#pragma once

#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <SDL2/SDL.h>

#include "../physics/Point.h"
#include "../physics/Vector2D.h"

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

class Viewport {
    public:

        void Update(float dt);
        inline static Viewport* GetInstance(){
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new Viewport();
        }

        inline SDL_Rect GetViewBox(){
            return m_viewBox;
        }

        inline Vector2D GetPosition(){
            return m_Position;
        }

        inline void SetTarget(Point* target){
            m_Target = target;
        }

    private:
        Viewport(){
            m_viewBox = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
        };
        Point* m_Target;
        Vector2D m_Position;

        SDL_Rect m_viewBox;

        static Viewport* s_Instance;
};

#endif