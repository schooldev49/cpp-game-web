#pragma once
#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <SDL2/SDL.h>
#include <vector>
#include "../map/MapChunk.h"
#include "../map/Map.h"
#include "../systemfiles/Engine.h"

class CollisionHandler {
    public:
        bool checkCollision(SDL_Rect a, SDL_Rect b);
        bool MapCollision(SDL_Rect a);

        inline static CollisionHandler* GetInstance(){
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new CollisionHandler();
        }
    private:
        CollisionHandler();
        TileMap m_colTileMap;
        MapChunk* m_CollisionLayer;
        static CollisionHandler* s_Instance;
};

#endif