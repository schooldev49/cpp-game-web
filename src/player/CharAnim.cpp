#include "CharAnim.h"
#include "../graphics/TextureManager.h"

CharAnim::CharAnim(bool repeat): Animation(repeat){

}

void CharAnim::Draw(float x, float y, int width, int height, float xScale, float yScale, SDL_RendererFlip flip){
    TextureManager::GetInstance()->DrawFrame(m_textureID,x,y,width,height,m_spriteRow,m_currentFrame,flip);
}

void CharAnim::Update(float dt){
   m_currentFrame = (SDL_GetTicks()/m_Speed) % m_frameCount;
}

void CharAnim::SetProps(std::string tID, int sRow, int fCount, int speed){
    m_Speed = speed;
    m_frameCount = fCount;
    m_textureID = tID;
    m_spriteRow = sRow;
}

