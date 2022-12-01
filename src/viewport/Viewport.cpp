#include "Viewport.h"

Viewport* Viewport::s_Instance = nullptr;

void Viewport::Update(float dt){
    if (m_Target != nullptr){
        m_viewBox.x = m_Target->X - SCREEN_WIDTH / 2;
        m_viewBox.y = m_Target->Y - SCREEN_HEIGHT / 2;
        if (m_viewBox.x < 0){
            m_viewBox.x = 0;
        }
        if (m_viewBox.y < 0){
            m_viewBox.y = 0;
        }

        if (m_viewBox.x > (2*SCREEN_WIDTH - m_viewBox.w)){
            m_viewBox.x = (2*SCREEN_WIDTH - m_viewBox.w);
        }

        if (m_viewBox.y > (2*SCREEN_HEIGHT - m_viewBox.h)){
            m_viewBox.y = (2*SCREEN_HEIGHT - m_viewBox.h);
        }

        m_Position = Vector2D(m_viewBox.x,m_viewBox.y);
    }
}