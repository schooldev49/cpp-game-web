#include "Play.h"

bool Play::Init(){
    levelSelector = false;
    m_Ctxt = Engine::GetInstance()->GetRenderer();

    TextureManager::GetInstance()->ParseTexture("assets/textures.tml");
   // m_LevelMap = MapParser::GetInstance()->Load("assets/maps/map.tmx");

}