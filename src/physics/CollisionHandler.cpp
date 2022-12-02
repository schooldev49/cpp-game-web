#include "CollisionHandler.h"
#include <iostream>
CollisionHandler* CollisionHandler::s_Instance = nullptr;

CollisionHandler::CollisionHandler(){
    std::cout << "wow\n";
    m_CollisionLayer = (MapChunk*)Engine::GetInstance()->GetMap()->GetMapChunks().back();
    m_colTileMap = m_CollisionLayer->GetTileMap();
    for (int i=0; i<m_colTileMap.size(); i++){
        for (int j=0; j<m_colTileMap.size(); j++){
            std::cout << m_colTileMap[j][i];
        }
    }
}

bool CollisionHandler::checkCollision(SDL_Rect a, SDL_Rect b){
    bool x_Overlaps = (a.x < b.x + b.w) && (a.x + a.w > b.x);
    bool y_Overlaps = (a.y < b.y + b.h) && (a.y + a.h > b.y);
    return (x_Overlaps && y_Overlaps);
}

bool CollisionHandler::MapCollision(SDL_Rect a){
    const int tSize = 32;
    const int rowCount = 20;
    const int colCount = 60;


    int leftTile = a.x/tSize;
    int rightTile = (a.x + a.w)/tSize;

    int topTile = a.y/tSize;
    int bottomTile = (a.y + a.h)/tSize;

    if (leftTile < 0) leftTile = 0;
    if (rightTile > colCount) rightTile = colCount;

    if (topTile < 0) topTile = 0;
    if (bottomTile > rowCount) bottomTile = rowCount;

    for (int i = leftTile; i <= rightTile; ++i){
        for (int j = topTile; j <= bottomTile; ++j){
            if (m_colTileMap[j][i] > 0){
                return true;
            }
        }
    }
    return false;

}