#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H

#include "GameObject.h"
#include <string>

class Character : public GameObject {

    public:
        Character(Properties* props): GameObject(props){

        }
        virtual void Draw()=0;
        virtual void Clean()=0;
        virtual void Update(float dt)=0;
    private:
        std::string m_Name;
};

#endif