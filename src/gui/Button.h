#pragma once
#ifndef BUTTON_H

#define BUTTON_H

#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include "../input/Input.h"
#include "../player/GameObject.h"
#include "../graphics/TextureManager.h"

using TextureIdList = std::vector<std::string>;

enum ButtonState {
    NORMAL = 0,
    HOVER = 1,
    PRESSED = 2
};


class Button : public GameObject {
    public:
    //     Properties(std::string textureID, int x, int y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE){

        Button(int x, int y, int width, int height, void (*callback)(), TextureIdList txtrIds): GameObject(new Properties(txtrIds[NORMAL],x,y,width,height)){
            m_Transform->X = x;
            m_Transform->Y = y;
            m_Callback = callback;
            m_TextrIds = txtrIds; 
            TextureManager::GetInstance()->QueryTexture(tID, &m_width, &m_height);
            m_Shape = {(int)m_Transform->X, (int)m_Transform->Y, m_width,m_height};
        }

        ~Button(){
            m_TextrIds.clear();
            m_TextrIds.shrink_to_fit();
        }
        virtual void Draw() override{
            //     TextureManager::GetInstance()->Draw("bg",0,0,2100,1050,1,1,0.05);
            TextureManager::GetInstance()->Draw(tID, m_Transform->X, m_Transform->Y, m_width, m_height);
        }
        virtual void Clean() override {
            for (auto id : m_TextrIds){
                TextureManager::GetInstance()->Drop(id);
            }

            m_TextrIds.clear();
            m_TextrIds.shrink_to_fit();
        }

        virtual void Update(float dt) override {
            int x, y = 0;
            SDL_GetMouseState(&x,&y);
            SDL_Point point = {x, y};

            if (SDL_PointInRect(&point,&m_Shape)){
                if (Input::GetInstance()->isDown() && m_isReleased){
                    m_Callback();
                    m_isReleased = false;
                    tID = m_TextrIds[PRESSED];
                } else if (!Input::GetInstance()->isDown()){
                    m_isReleased = true;
                    tID = m_TextrIds[HOVER];
                } 
            } else {
                tID = m_TextrIds[NORMAL];
            }
        } 
        SDL_Rect m_Shape;
        bool m_isReleased;
        void (*m_Callback)();
        TextureIdList m_TextrIds;
        std::string tID;
};

#endif