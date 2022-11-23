#pragma once

#ifndef MAINCHAR_H
#define MAINCHAR_H

#include "Character.h"

class MainChar : public Character {

    public:
        MainChar(Properties* props);
        virtual void Draw();
        virtual void Clean();
        virtual void Update(float dt);
    private:
        int m_Row, m_Frame, m_FrameCount, m_AnimSpeed;
    
};


#endif