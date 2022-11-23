#include "MainChar.h"
#include <SDL2/SDL.h>
#include "../graphics/TextureManager.h"


MainChar::MainChar(Properties* props): Character(props) {
    m_Row = 1;
    m_FrameCount = 6;
    m_AnimSpeed = 80;
}

void MainChar::Draw(){
    TextureManager::GetInstance()->DrawFrame(m_TextureID, m_Transform->X, m_Transform->Y, m_width, m_height, m_Row, m_Frame);
}

void MainChar::Update(float dt){
    m_Frame = (SDL_GetTicks()/m_AnimSpeed) % m_FrameCount;
}

void MainChar::Clean(){
    TextureManager::GetInstance()->Clean();
}