#pragma once

#ifndef MAPPARSER_H
#define MAPPARSER_H

#include "../tinyxml/tinyxml.h"
#include <map>
#include <string>
#include "Map.h"
#include "MapChunk.h"

class MapParser {
    public:
        bool Load(std::string id="level1", std::string source = "assets/maps/level1.tmx");
        void Clean();
        bool CanEnterMap(std::string source);
        inline Map* GetMaps(std::string id){
            return m_mapDict[id];
        }
        inline static MapParser* GetInstance(){
            return s_Instance = (s_Instance != nullptr)? s_Instance : new MapParser();
        }
    private:
        MapParser(){};
        static MapParser* s_Instance;
        std::map<std::string, Map*> m_mapDict;
        bool Parse(std::string id, std::string source);
        Tiles ParseTileset(TiXmlElement* xmlTileset);
        MapChunk* ParseTileLayer(TiXmlElement* xmlTileSet, TilesetList tilesets, int tilesize, int rowcount, int colcount); 
};


#endif