#include "SequenceAnim.h"
#include "../graphics/TextureManager.h"
#include "../tinyxml/tinyxml.h"
SequenceAnim::SequenceAnim(bool repeat): Animation(repeat){

}

void SequenceAnim::drawFrame(float x, float y, float xScale, float yScale, SDL_RendererFlip flip){
    TextureManager::GetInstance()->Draw(m_currentSeq.tIDs[m_currentFrame],x,y,m_currentSeq.Width,m_currentSeq.Height,flip);
}

void SequenceAnim::Update(float dt){
    if (m_Repeat || !m_isEnded){
        m_isEnded = false;
        m_currentFrame = (SDL_GetTicks()/m_currentSeq.Speed) % m_currentSeq.FrameCount;
    }

    if (!m_Repeat && m_currentFrame == (m_currentSeq.FrameCount-1)){
        m_isEnded = true;
        m_currentFrame = (m_currentSeq.FrameCount-1);
    }
}

void SequenceAnim::setCurrentSeq(std::string seqID){
    if (m_seqMap.count(seqID) > 0){
        m_currentSeq = m_seqMap[seqID];
    }
}

void SequenceAnim::Parse(std::string source){
    TiXmlDocument xml;
    xml.LoadFile(source);
    if (xml.Error()){
        
    }

    TiXmlElement* root = xml.RootElement();
    for (TiXmlElement* e=root->FirstChildElement(); e!=nullptr; e=e->NextSiblingElement()){
        if (e->Value() == std::string("sequence")){
            Sequence seq;
            std::string seqID = e->Attribute("id");
            e->Attribute("speed",&seq.Speed);
            e->Attribute("width",&seq.Width);
            e->Attribute("height",&seq.Height);
            e->Attribute("frameCount",&seq.FrameCount);
            for (TiXmlElement* frame=e->FirstChildElement(); frame!=nullptr; frame=frame->NextSiblingElement()){
                seq.tIDs.push_back(frame->Attribute("textureID"));
            }
            m_seqMap[seqID] = seq;
        }
    }
}