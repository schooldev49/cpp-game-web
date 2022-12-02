#pragma once

#ifndef COLLISION_H
#define COLLISION_H

#include <SDL2/SDL.h>

class Collision {
    public:
        inline SDL_Rect Get(){
            return m_Box;
        }
        inline void SetBuffer(int x, int y, int w, int h){
            m_Buffer = {
                x,
                y,
                w,
                h
            };
        }
        void Set(int x, int y, int w, int h){
            Vector2D cam = Viewport::GetInstance()->GetPosition();
            m_Box = {
                x + m_Buffer.x,
                y + m_Buffer.y,
                w - m_Buffer.w, 
                h - m_Buffer.h
            };
        }
        bool Collides(){
            return CollisionHandler::GetInstance()->MapCollision(m_Box);
        }

        void Draw(){
            Vector2D cam = Viewport::GetInstance()->GetPosition();
            SDL_Rect box = {m_Box.x - cam.X,m_Box.y - cam.Y, m_Box.w,m_Box.h};
            SDL_SetRenderDrawColor( Engine::GetInstance()->GetRenderer(), 239, 0, 0, 0.8 );
            SDL_RenderDrawRect(Engine::GetInstance()->GetRenderer(),&box);
        }
    protected:
        SDL_Rect m_Box;
        SDL_Rect m_Buffer;
};


#endif