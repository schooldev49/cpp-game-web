#pragma once

#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL2/SDL.h>
#include <string>

class Animation {
    public:
        Animation(bool repeat=true): m_Repeat(repeat){
            m_isEnded = false;
        };
        
        virtual void Update(float dt)=0;
        inline bool endedAnim(){
            return m_isEnded;
        }
       /*
         void Draw(float x, float y, int spriteWidth, int spriteHeight);
        void SetProps(std::string textureID, int spiritRow, int frameCount, int animSpeed, SDL_RendererFlip flip=SDL_FLIP_NONE);
        */
    protected:
        int m_currentFrame;
        bool m_Repeat;
        bool m_isEnded;
};

#endif