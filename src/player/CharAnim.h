#pragma once

#ifndef CHARANIM_H
#define CHARANIM_H

#include "Animation.h"
class CharAnim : public Animation {
    public:
        CharAnim(bool repeat=true);
        virtual void Update(float dt);
        void Draw(float x, float y, int spriteWidth, int spriteHeight, float xScale=1, float yScale=1, SDL_RendererFlip = SDL_FLIP_NONE);
        void SetProps(std::string textureID, int spriteRow, int frameCount, int speed);
    protected:
        int m_Speed;
        int m_spriteRow;
        int m_frameCount;
        std::string m_textureID;
};
#endif