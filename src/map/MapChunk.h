#pragma once

#ifndef MapChunk_H
#define MapChunk_H

#include "Layer.h"
#include <vector>
#include <string>
struct Tiles {
    int First, LastID, rowCount, colCount, tileCount, tileSize = 0;
    std::string Name, Source = "";
    
};

using TilesetList = std::vector<Tiles>;
using TileMap = std::vector<std::vector<int>>;
class MapChunk : Layer {
    public:
        MapChunk(){};
        MapChunk(int p_tileSize, int p_rowCount, int p_colCount, TileMap p_tileMap, TilesetList p_tileSets);
        virtual void Render();
        virtual void Update();
        inline TileMap GetTileMap(){
            return m_Tilemap;
        }

        int getRowCount(){
            return m_rowCount;
        }
        int getColCount(){
            return m_ColCount;
        }
        int GetWidth(){
            return m_Tilemap[0].size();
        }
        int GetHeight(){
            return m_Tilemap.size();
        }

       void Clean(){
            m_Tilemap.clear();
            m_tileSets.clear();
       }
    private:
        int m_tileSize;
        int m_rowCount;
        int m_ColCount;
        TileMap m_Tilemap;
        TilesetList m_tileSets;
};

#endif