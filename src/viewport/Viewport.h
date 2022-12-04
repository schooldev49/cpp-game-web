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

        inline int GetSceneWidth(){
            return m_SceneWidth;
        }

        inline int GetSceneHeight(){
            return m_SceneHeight;
        }

        inline void SetSceneLimit(int w, int h){
            m_SceneWidth = w;
            m_SceneHeight = h;
        }
    private:
        Viewport(){
            m_viewBox = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
        };
        Point* m_Target;
        Vector2D m_Position;

        SDL_Rect m_viewBox;
        int m_SceneWidth, m_SceneHeight = 0;
        static Viewport* s_Instance;
};

#endif