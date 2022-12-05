#pragma once

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string> 
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <SDL2/SDL_ttf.h>

class TextureManager {

    public:
        static TextureManager* GetInstance(){
            return s_Instance = (s_Instance != nullptr)? s_Instance : new TextureManager();
        };
        bool Load(std::string id,std::string filename);
        void Drop(std::string id);
        void Clean();
        bool ParseTexture(std::string source);
        void Draw(std::string id, int x, int y, int width, int height, float scaleX=1, float scaleY=1, float scrollRatio=0, SDL_RendererFlip flip=SDL_FLIP_NONE);
        void DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip=SDL_FLIP_NONE);
        void DrawTile(std::string tid, int tileSize, int x, int y, int row, int frame, SDL_RendererFlip flip=SDL_FLIP_NONE);
        void QueryTexture(std::string id, int* out_w, int* out_h);
        void AddFont(std::string id, std::string path, int fontSize);
        TTF_Font* GetFont(std::string id);
    private:
        TextureManager(){}
        std::map<std::string, SDL_Texture*> m_TextureMap; 
        std::map<std::string, TTF_Font*> m_FontMap;
        static TextureManager* s_Instance;
};

#endif