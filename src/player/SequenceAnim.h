#pragma once

#ifndef SEQUENCEANIM_H
#define SEQUENCEANIM_H

#include <map>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "Animation.h"

struct Sequence {
    int Speed;
    int FrameCount;
    int Width;
    int Height;
    std::vector<std::string> tIDs;
};

class SequenceAnim : public Animation {
    public:
        SequenceAnim(bool repeat=true);

        virtual void Update(float dt);
        void Parse(std::string source);
        void setCurrentSeq(std::string seqID);
        void setRepeat(bool repeat){
            m_Repeat = repeat;
        }

        void drawFrame(float x, float y, float xScale=1, float yScale=1, SDL_RendererFlip flip=SDL_FLIP_NONE);
    protected:
        Sequence m_currentSeq; 
        std::map<std::string, Sequence> m_seqMap;
};

#endif