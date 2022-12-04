#pragma once

#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <vector>
#include "Layer.h"
#include "MapChunk.h"
typedef unsigned int uint;

class Map : public Layer {
    public:
        void Render(){
            for (uint i=0; i<m_MapChunks.size(); i++){
                m_MapChunks[i]->Render();
            }
        }
        void Update(){
            for (uint i=0; i<m_MapChunks.size(); i++){
                m_MapChunks[i]->Render();
            }
        }

        std::vector<MapChunk*> GetMapChunks(){
            std::cout << "Getting map chunk";
            return m_MapChunks;
        }
        std::vector<MapChunk*> m_MapChunks;
    private:
        friend class MapParser;
};

#endif