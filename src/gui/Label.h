#pragma once

#ifndef LABEL_H
#define LABEL_H

#include "../graphics/TextureManager.h"
#include "../player/GameObject.h"
#include "../systemfiles/Engine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>

class Label : public GameObject {
    // Properties(std::string textureID, int x, int y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE){
    public:
    Label(int x, int y, int w, int h, std::string text, std::string font, SDL_Color& color) : GameObject(new Properties("",x,y,w,h)){
        labelText = text;
        labelFont = font;
        textColor = color;
        position.x = x;
        position.y = y;
        position.w = w;
        position.h = h;

        SetLabelText(labelText,labelFont);
    }
    ~Label(){

    }


    void SetLabelText(std::string text, std::string font){
        SDL_Surface* surf = TTF_RenderText_Blended(TextureManager::GetInstance()->GetFont(font),labelText.c_str(),textColor);
        labelTexture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(),surf);
        SDL_FreeSurface(surf);

        SDL_QueryTexture(labelTexture, nullptr, nullptr, &position.w, &position.h);
    }
    virtual void Draw() override{
        SDL_RenderCopy(Engine::GetInstance()->GetRenderer(),labelTexture,nullptr, &position);
    }

    virtual void Update(float dt) override {

    }

    virtual void Clean() override {
        
    }
    protected:
        SDL_Rect position;
        std::string labelText;
        std::string labelFont;
        SDL_Color textColor;
        SDL_Texture* labelTexture;

};


#endif